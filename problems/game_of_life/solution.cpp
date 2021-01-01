class Solution {
public:
    int m ,n;
    int row[3]={-1,0,1};
    int getLive(vector<vector<int>>& board, int x, int y){
        int l=0;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++)
            {
                if (row[i] || row[j])                     
                {
                    int r = x + row[i];
                    int c = y + row[j];
                    if (r>=0 && r<m && c>=0 && c<n)
                        l += board[r][c] > 0;         
                }                
            }
        }
        return l;
        /*
        if (i>0){
            if (j>0)
                l += board[i-1][j-1] > 0;
            l += board[i-1][j]> 0;
            if (j+1<n)
                    l += board[i-1][j+1]> 0;
        }
        if (j>0)
           l += board[i][j-1]> 0;
        if (j+1<n)
           l += board[i][j+1]> 0;        
        if (i+1<m ){
            if (j>0)
                l += board[i+1][j-1]> 0;
            l += board[i+1][j]> 0;
            if (j+1<n)
                    l += board[i+1][j+1]> 0;
        }        
        return l;*/
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){        
                int l = getLive(board,i,j);
                if (board[i][j]!=0){                    
                    if (l < 2) board[i][j]=2;
                    else if (l > 3) board[i][j]=2;
                }
                else if (l==3) board[i][j]=-1;
            }
        }
        
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                
                if (board[i][j]==-1){
                    board[i][j]=1;
                }
                else if (board[i][j]==2)
                    board[i][j]=0;
            }
        }        
        
    }
};