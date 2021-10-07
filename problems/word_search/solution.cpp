class Solution {
public:
    int  N, M, W;
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size(), N = board[0].size(),W =word.size();
        for (int i=0; i<M; i++){
            for (int j=0;j<N; j++){
                if (word[0] == board[i][j]){
                    if (dfs(board, i,j,word,0)) return true;
                }
            }
        }
        return false;
    }
    int dfs(vector<vector<char>>& board, int i, int j,string& word, int k){
        if (i >= M || i<0 || j<0 ||j >=N || board[i][j] != word[k]) return false;
        if (k == W-1) return true;
        board[i][j]=1;
        if (dfs(board, i+1,j,word,k+1) || dfs(board, i,j+1,word,k+1) ||
            dfs(board, i-1,j,word,k+1) || dfs(board, i,j-1,word,k+1)){
            return true;
        }
        board[i][j]=word[k];
        return false;
    }
};