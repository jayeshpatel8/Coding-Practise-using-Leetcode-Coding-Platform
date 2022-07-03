class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size() , mod = 1e9 +7 ;
        long ans=  0;
        vector<vector<int>> dp(m,vector<int> (n,1));
        vector<array<int, 3> > h;
        int dirs[5] = {-1,0,1,0,-1};
         for (int i=0; i<m; i++){
            for (int j=0;j<n; j++){
                h.push_back({grid[i][j],i,j});
            }
         }
        sort(begin(h),end(h));
        for (auto i1 : h){
            {
                int i = i1[1], j = i1[2];
                for (int k=0; k<4; k++){
                    int r = i + dirs[k] ,c = j + dirs[k+1];
                    if (r<0 ||c <0 || r>=m || c>=n || i1[0] >= grid[r][c]) continue;
                     dp[r][c] = (dp[r][c]+dp[i][j])%mod;
                }
                
            }
         
        }
        for (int i=0; i<m; i++){
            for (int j=0;j<n; j++){
                ans =  (ans  + dp[i][j]) %mod;
              
            }
         
        }
                
        return ans;
    }
};