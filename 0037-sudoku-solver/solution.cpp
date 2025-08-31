class Solution {
public:
    int row[9][10]={},col[9][10]={},box[3][3][10]={};
    void solveSudoku(vector<vector<char>>& board) {
        
        for (int r = 0; r<9; r++){
            for (int c=0; c<9; c++){
                if (board[r][c] != '.'){
                    int n = board[r][c] - '0';
                    row[r][n] = col[c][n] = box[r/3][c/3][n]=1; 
                }
            }
        }
        bt(board,0);
    }
    bool bt(vector<vector<char>>& board, int n){
        int r = n/10, c = n%10;
        if (r==9) return true;
        
        if (board[r][c]!='.') return bt(board,n+1);
        for ( int i=1; i<=9; i++){
            if (row[r][i] || col[c][i]|| box[r/3][c/3][i]) continue;
            board[r][c] = i+'0'; row[r][i] = col[c][i]= box[r/3][c/3][i] = 1;
            if (bt(board,n+1)) return true;
            row[r][i] = col[c][i]= box[r/3][c/3][i] = 0;
        }
        board[r][c] = '.';
        return false;
    }
};
