class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();

        vector<int> dp(N);
        iota(begin(dp),end(dp),0);

        for (int r=0; r<M; r++){
            for (auto &c1 : dp){
                if (c1 <0 || c1 >= N) continue;
                auto c2 = grid[r][c1] > 0 ? c1+1 : c1-1;
                if (c2 < 0 || c2 >=N || grid[r][c1] != grid[r][c2]) c1=-1;
                else c1 = c2;                
            }
        }
        return dp;
    }
};