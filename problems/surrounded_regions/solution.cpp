class Solution {
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!='O') return;
        board[i][j] = '#';
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(); if (m == 0) return;
        int n = board[0].size(); if (n == 0) return;
        m -= 1;
        n -= 1;

        for (int i = 0; i <= m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n] == 'O') {
                dfs(board, i, n);
            }
        }
        for (int j = 0; j <= n; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if (board[m][j] == 'O') {
                dfs(board, m, j);
            }
        }

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
/*
class Solution {
    vector<vector<int>> vis;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int m, n;
    
    bool isValid(int i, int j) {return i >= 0 && i < m && j >= 0 && j < n;}
    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '#';
        int x, y;
        for (int k = 0; k < 4; k++) {
            x = i+dx[k];
            y = j+dy[k];
            if (isValid(x,y) && !vis[x][y] && board[x][y] == 'O') {
                vis[x][y] = 1;
                dfs(board, x, y);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(); if (m == 0) return;
        int n = board[0].size(); if (n == 0) return;
        Solution::m = m;
        Solution::n = n;
        vis.resize(m, vector<int>(n));
        // cout<<"initial:\n"<<board<<endl;
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n-1] == 'O') {
                dfs(board, i, n-1);
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if (board[m-1][j] == 'O') {
                dfs(board, m-1, j);
            }
        }
        // cout<<board<<endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
        // cout<<"final\n"<<board<<endl;
        return;
    }
};
*/