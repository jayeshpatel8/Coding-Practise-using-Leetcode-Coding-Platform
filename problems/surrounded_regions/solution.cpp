class Solution {
public:
    int M, N;
    void solve(vector<vector<char>>& board) {
        M = board.size(), N  = board[0].size();
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if ((i==0 || j==0 || i==M-1 || j==N-1 ) && board[i][j] == 'O'){
                    dfs(board,i,j);
                }
            }
        }
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#'){
                    board[i][j] = 'O';
                }                
            }
        }        
    }
    void dfs(vector<vector<char>>& board, int i = 0, int j = 0){
        if (i<0 ||  j<0 || i>=M || j>=N ) return ;
        
        if (board[i][j]=='X' || board[i][j]=='#') return ;
        board[i][j] = '#';
        dfs(board,i-1,j ); dfs(board,i,j-1 ) ; dfs(board,i,j+1 ) ; dfs(board,i+1,j );

    }
    
};