class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> ans(N-2, vector<int>(N-2));
        for (int i=0; i<N-2; i++){
            for (int j=0; j<N-2; j++){
                for (int r=i; r<i+3; r++)
                    for (int c=j; c<j+3; c++)
                        ans[i][j] = max(ans[i][j], grid[r][c]);
            }
        }
        return ans;
    }
};