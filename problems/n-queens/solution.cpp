class Solution {
public:
    vector<vector<string>> res;
    int N;
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<bool> visited(n,0);
        vector<string> board(n,string(n, '.'));
        solveNQueens(n,0,visited,board);
        
        return res;
    }
    void solveNQueens(int n, int r, vector<bool>& visited, vector<string>& board){
        if (r == n ) {
            res.push_back(board);
            return;
        }
       //for (; c < n; c++){
           for (int c=0; c < n; c++){
               if ( allowed(board,r,c)){
                   visited[r]=1;
                   board[r][c]='Q';
                   
                   solveNQueens(n,r+1,visited,board);
                   
                   board[r][c]='.';
                   visited[r]=0;
               }
           }
           return ;
       //}   
    }
    bool allowed(vector<string>& s, int r , int c){
    int n = s.size();
    // check for col
    for (int i =0; i<n; i++)
        if (s[i][c]=='Q' ) return false;
    // right cross check
    for (int i =r-1,j=c-1;  i>=0 && j >=0; i--,j--)
        if (s[i][j]=='Q') return false;        
    for (int i =r-1,j=c+1;  j<n && i>=0 ; i--,j++)
        if (s[i][j]=='Q') return false;
    return true;
    }
};