class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        int n= mt.size(), m=mt[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> h;
        h.push({0, 0, 0}); // arrive time, i, j
        mt[0][0] = -1;

        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!h.empty()) {
            vector<int> cur = h.top();
            h.pop();
            int t = cur[0], i = cur[1], j = cur[2];
            if (t >= dp[i][j]) continue;
            if (i == n - 1 && j == m - 1) return t;
            dp[i][j] = t;

            for (auto& dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (0 <= x && x < n && 0 <= y && y < m && dp[x][y] == INT_MAX) {
                    h.push({max(mt[x][y], t) + 1, x, y});
                }
            }
        }
        return -1;
    }
};
