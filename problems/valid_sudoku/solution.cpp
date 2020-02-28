
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    short row[9]={0};
    short col[9]={0};
    short box[9]={0};
        for (int r =0; r < 9; r++)
        {
            for (int c=0; c<9; c++)
            {
                if (board[r][c] == '.') continue;
                short id = 1 << (board[r][c] -'0');
                if (row[r] & id || col[c] & id || box[r/3*3+c/3]&id)
                    return false;
                row[r] |= id ; col[c] |= id ; box[r/3*3+c/3]|=id;
            }
        }
        return true;
    }
};