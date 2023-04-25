class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int M=  grid.size(), N= grid[0].size();
        int ans = 0;
        for (int c=1; c<N-1; c++){
            int sum = grid[0][c]+ grid[1][c];
            for (int r=2; r<M; r++){
                sum += grid[r][c];
                ans=  max(ans, sum + grid[r-2][c-1]+ grid[r-2][c+1] + grid[r][c-1] + grid[r][c+1]);
                sum -=grid[r-2][c];
            }
        }
        return ans;
    }
};