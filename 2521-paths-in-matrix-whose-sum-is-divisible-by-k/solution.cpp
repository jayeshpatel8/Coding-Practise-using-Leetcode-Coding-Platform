const int mod = 1e9 + 7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> prev(m + 1, vector<int>(K, 0));
        prev[1][0] = 1;

        for(int i = 0; i < n; i++){
            vector<vector<int>> curr(m + 1, vector<int>(K, 0));
            for(int j = 0; j < m; j++){
                for(int k = 0; k < K; k++){
                    int id = (k + grid[i][j]) % K;
                    curr[j + 1][id] = (0ll + curr[j + 1][id] + prev[j + 1][k] + curr[j][k]) % mod;
                }
            }
            swap(prev, curr);
        }

        return prev[m][0];
    }
};
