class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10]={}, col[9][10]={}, box[3][3][10]={};
        
        for( int r=0; r< 9; r++)
            for( int c = 0; c < 9; c++)
                if (board[r][c] != '.'){
                    int n = board[r][c] - '0';
                    if (row[r][n]++ > 0 || col[c][n]++ > 0 || box[r/3] [c/3][n]++ > 0)                   
                        return false;
                }
        
        return true;
    }
};
