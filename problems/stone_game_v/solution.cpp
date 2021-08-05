class Solution {
public:
    int dp[500][500];
    int stoneGameV(vector<int>& V) {
        int N = V.size();
        vector<int> sum(N+1);
    
        for (int i=0; i<N; i++)
            sum[i+1]=V[i] +sum[i];
        
        return play(V,sum,0,N-1);
    }
    int play(vector<int>& V , vector<int>& sum, int i, int j){
        
        if(j==1+i) return min(V[i], V[j]);
        if(dp[i][j]) return dp[i][j];
        int ans = 0 ;
        for (int k=i; k<j; k++){
            int lsum = sum[k+1]-sum[i], rsum = sum[j+1]-sum[k+1];
            if (lsum <= rsum)
                ans = max(ans , lsum  + play(V,sum,i,k) );
            if (lsum >= rsum)
                ans = max(ans , rsum  + play(V,sum,k+1,j) );
        }        
        return dp[i][j] = ans;
    }
/*
    int stoneGameV(vector<int>& V) {
        int N = V.size();
        //vector<vector<int>> dp(N, vector<int>(N)) ;
        vector<int> sum(N+1);
        for (int i=0; i<N; i++){
            sum[i+1]=V[i] +sum[i];
        }
        for (int l = 1; l<N; l++){
            for (int i=0; i<N-l; i++){
                int j=i+l, ans=0;
                for (int k=i; k<j; k++){
                    int lsum = sum[k+1]-sum[i], rsum = sum[j+1]-sum[k+1];
                    if (lsum < rsum)
                        ans = max(ans , lsum  + dp[i][k] );
                    else if (lsum > rsum)
                        ans = max(ans , rsum  + dp[k+1][j] );
                    else
                        ans = max(ans , rsum  + max(dp[i][k], dp[k+1][j]) );
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][N-1];
    }
*/    
};