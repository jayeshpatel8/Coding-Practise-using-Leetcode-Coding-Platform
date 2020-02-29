int empty(vector<vector<char>>& board , int *r, int* c)
{
    for(*r=0;*r<9;(*r)++)
    {
        for(*c=0;*c<9;(*c)++)
        {
            if(board[*r][*c]=='.')
            {
                return 1;
            }
        }
    }
    return 0;    
}
int backtrack(vector<vector<char>>& board , short *row, short *col, short *box)
{
    int r=0, c=0;
    if(!empty(board,&r,&c))
        return 1;
    for (int k=1; k<=9; k++)
    {
        #if 1
        short id = 1 << k;
        if (row[r] & id || col[c] & id || box[r/3*3+c/3]&id)  
            continue;
        else
        {
            row[r] |= id ; col[c] |= id ; box[r/3*3+c/3]|=id;
            board[r][c]='0'+k;
             if (1 == backtrack(board ,row, col, box))
                 return 1; 
            board[r][c]='.';
            row[r] &= ~id ; col[c] &= ~id ; box[r/3*3+c/3] &=~id;
        }    
        #endif
    }
    //cout << "r,c:"<< r << "," << c<< "|";
    return 0;
}
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
    short row[9]={0};
    short col[9]={0};
    short box[9]={0};
        for (int r =0; r < 9; r++)
        {
            for (int c=0; c<9; c++)
            {
                if (board[r][c] == '.') continue;
                short id = 1 << (board[r][c] -'0');
                row[r] |= id ; col[c] |= id ; box[r/3*3+c/3]|=id;
            }
        }   
        cout << backtrack(board ,row, col, box); 
    }
};