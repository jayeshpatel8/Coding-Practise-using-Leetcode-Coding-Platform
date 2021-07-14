class Solution {
public:
    int dp2[101][101][31];
    int prefix[101];
    int K;
    int mergeStones(vector<int>& stones, int k) {
        int l = stones.size();
        K=k;
        if ((l-1)%(k-1) != 0 ) return -1;
        memset(dp2,-1,sizeof(dp2[0])*l);
        prefix[0] = stones[0];
        for (int i=1; i<l;i++) prefix[i] = prefix[i-1] + stones[i]; 
        int dp[l+1][l+1];
        memset(dp,0,sizeof(dp));
        for (int len = K; len<=l; len++){
            for (int i=0; i+len<=l; i++){
                int j = i+len-1;
                dp[i][j] = 1e8;
                for (int mid=i; mid<j; mid+=K-1){
                    dp[i][j] = min(dp[i][j], dp[i][mid] +dp[mid+1][j]);
                }
                if ((j-i)%(k-1) == 0 )
                    dp[i][j] += prefix[j] - (i>0? prefix[i-1] : 0);
            }
        }
        return dp[0][l-1];
        int ans = cost(stones,0,l-1,1);
        return ans;
    }
    int cost(vector<int>& stones, int i, int j, int piles){
        if (dp2[i][j][piles] != -1) return dp2[i][j][piles];
        if (i==j) return piles==1 ?  0 : 1e8;
                
        int ans = 1e8;
        if ( piles == 1){
            ans = cost(stones,i,j,K) + prefix[j]- (i>0? prefix[i-1] : 0);
        }else{
            for (int k=i; k<j;k++)
                ans = min(ans, cost(stones,i,k,piles-1) + cost(stones,k+1,j,1));
        }
        return dp2[i][j][piles]=ans;
    }
};