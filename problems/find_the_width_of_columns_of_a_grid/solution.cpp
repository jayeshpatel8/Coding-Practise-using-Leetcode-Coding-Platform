class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int M =  grid.size(), N = grid[0].size();
        vector<int> ans;
        for (int c  = 0; c <N; c++){
            size_t l  = 1;
            for (int r = 0; r < M; r++){
                l = max(l, (to_string(grid[r][c]).size()));
            }
            ans.push_back(l);
        }
        return ans;
    }
};