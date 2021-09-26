class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int M = board.size(), N = board[0].size(), W  = word.size();
        for (int i =0; i <M; i++){
            for (int j =0; j < N; j++){
                if  (board[i][j] == '#' || (board[i][j] != ' ' && board[i][j] != word[0])) continue;
                //r
                if((j==0 || board[i][j-1] == '#') && (j+W==N || (j+W<N && board[i][j+W] =='#')) ){
                    int k = 0;
                    for (; k<W;k++){
                        if(board[i][j+k] == ' ' || board[i][j+k] == word[k]) continue;
                        break;
                    }
                    if(k == W) return true;
                }
                //l
                if((j==N-1 || board[i][j+1] == '#') && (j-W==-1 || (j-W>=0 && board[i][j-W] =='#') )){
                    int k = 0;
                    for (; k<W;k++){
                        if(board[i][j-k] == ' ' || board[i][j-k] == word[k]) continue;
                        break;
                    }
                    if(k == W) return true;
                }                
                //d
                if((i==0 || board[i-1][j] == '#') && (i+W==M || (i+W<M && board[i+W][j] =='#')) ){
                    int k = 0;
                    for (; k<W;k++){
                        if(board[i+k][j] == ' ' || board[i+k][j] == word[k]) continue;
                        break;
                    }
                    if(k == W) return true;
                }                   
                //u
                if((i==M-1 || board[i+1][j] == '#') && (i-W==-1 || (i-W>=0 && board[i-W][j] =='#') )){
                    int k = 0;
                    for (; k<W;k++){
                        if(board[i-k][j] == ' ' || board[i-k][j] == word[k]) continue;
                        break;
                    }
                    if(k == W) return true;
                }                                   
            }
        }
        return false;
    }
};