
class Solution {
public:
    int dp1[51][51][11], M, N, mod = 1e9 + 7;
    int ways(vector<string>& pizza, int k) {
         M = pizza.size(), N = pizza[0].size();
        vector<vector<int>> psum(M+1,vector<int>(N+1));
        for (int i=0; i<M; i++){            
            for (int j=0; j<N; j++){
                psum[i+1][j+1] = psum[i][j+1]+psum[i+1][j]-psum[i][j] + (pizza[i][j]=='A');
            }
        }
        memset(dp1,-1, sizeof(dp1));
        return dfs(pizza, psum, 0,0,k);
    }
    bool getApple(vector<vector<int>> &psum, int r1, int c1, int r2, int c2){
        return psum[r2+1][c2+1]-psum[r2+1][c1]-psum[r1][c2+1]+ psum[r1][c1];
    }
   
    int dfs(vector<string>& pizza, vector<vector<int>> &psum, int i, int j, int k){        
        if (k==1)
            return getApple(psum, i,j,M-1,N-1);
        
        if (dp1[i][j][k] != -1) return dp1[i][j][k];
        int ans = 0;
        for (int r=i; r<M-1; r++ )
            if (getApple(psum,i,j,r,N-1))
                ans =  (ans + dfs( pizza,psum,r+1,j,k-1)) % mod;

        for (int c=j; c<N-1; c++ )
            if (getApple(psum,i,j,M-1,c))
                ans =  (ans + dfs( pizza,psum,i,c+1,k-1)) % mod;

        return dp1[i][j][k] = ans;
    }
        
};