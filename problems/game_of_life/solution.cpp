class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans(board);
        for (int i=0  , m = board.size(),n = board[0].size(); i<m; i++){
            for (int j=0; j<n; j++){
                int cnt = 0;
                
                for (int k=max(0,j-1); k <min(n,j+2); k++){
                    if (i > 0 ) cnt +=board[i-1][k];
                    if (i < m -1 ) cnt +=board[i+1][k];
                }
                if (j>0) cnt +=board[i][j-1];
                if (j+1 < n) cnt +=board[i][j+1];

                if (board[i][j]){
                    if (cnt ==2 || cnt==3) continue;
                    ans[i][j]=0;
                }
                else{
                    if (cnt==3)
                        ans[i][j]=1;
                }
            }

        }
        board.swap(ans);        
    }
};