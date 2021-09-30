class Solution {
public:
    int N , k;
    int maxSizeSlices(vector<int>& slices) {
        N = slices.size();
        k = N/3;
        return max(cut(slices,0,N-2), cut(slices,1,N-1));
    }
    int cut(vector<int>& slices, int start, int end){
        int dp[N+1][k+1];
        memset(dp,0,sizeof(dp));
        
        for (int i=start+1 ; i<=end+1; i++){
            for (int j=1; j<=k; j++){
                if (i == start +1)
                    dp[i][j]=slices[start];
                else{
                    dp[i][j]= max( dp[i-1][j] , dp[i-2][j-1] + slices[i-1]);
                }
            }
        }
        return dp[end+1][k];
    }
};