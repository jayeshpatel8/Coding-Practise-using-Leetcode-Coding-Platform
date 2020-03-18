bool backtrace(vector<vector<char>>&  board,string& word,int i, int j,int k){
   
    int m=board.size(), n= board[0].size();
    if (board[i][j]==0 || board[i][j]!=word[k]) return false;
    
    int t = board[i][j];board[i][j]=0;
    if (word.size()-1 == k) return true;    
    // match
    if (i+1<m ) {
        if (backtrace(board,word,i+1,j,k+1)) return true;
    }
    if (j+1<n  ) {
        if (backtrace(board,word,i,j+1,k+1)) return true;
    }
    if (i-1>=0 ){
        if  (backtrace(board,word,i-1,j,k+1)) return true;
    }
    if (j-1>=0 ) {
        if  (backtrace(board,word,i,j-1,k+1)) return true;
    }
    board[i][j]=t;
    return false;
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
         int m=board.size(), n= board[0].size();
        
      vector<vector<bool>> used(m,vector<bool>(n,0));
         
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (board[i][j] == word[0] ){
                    if( backtrace(board,word,i,j,0)) return true;
                }
            }
        return false;
    }
};