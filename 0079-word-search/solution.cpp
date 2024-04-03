class Solution {
public:
     
    bool exist(vector<vector<char>>& board, string word) {
        for ( int i=0; i<board.size(); i++){
            for ( int j=0; j<board[0].size(); j++){
                if ( board[i][j] == word[0] && dfs(board, word, 0, i,j )) return true;
            }
        }
        return false;
    }
    int dirs[5] = {-1,0,1,0,-1};
    bool dfs(vector<vector<char>>& board, string word, int i, int r , int c){
        if (i == word.size()) return true;
        if (r<0 || c < 0 || r >= board.size() || c >= board[0].size()||word[i] != board[r][c]) return false;
        board[r][c] = 1;
        for (int d=0; d<4; d++){
            int r1 = r + dirs[d], c1 = c + dirs[d+1];
            if (dfs(board,word,i+1,r1,c1)) return true;
        }
        board[r][c] = word[i];
        return false;
    }
};
