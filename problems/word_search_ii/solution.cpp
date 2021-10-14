class Solution {
public:
    struct Trie{
      Trie * T[26]={};
        string w;
    };
    Trie root;
    int vis[12][12]={};
    void insert(vector<string>& words){
        for (auto s : words){            
            Trie * r = &root;
            for (auto ch : s){
                int c = ch-'a';
              if(!r->T[c])  
                r->T[c] = new Trie;
              r = r->T[c];
            }        
            r->w = s;            
        }
    }
    int N,M;
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        M = board.size(), N = board[0].size();
        insert(words);
        for (int i=0; i<M; i++){
            for (int j = 0; j<N; j++)
            {
                Trie * r = &root;
                {
                  if(r->T[board[i][j]-'a'] )  
                      dfs(board,i,j,r);
                }                        
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& board, int i, int j, Trie* r){
        if (i<0 ||j <0 || i>=M || j>=N  || vis[i][j] || r->T[board[i][j]-'a']==NULL) return;
        if (!r->T[board[i][j]-'a']->w.empty()) ans.push_back( r->T[board[i][j]-'a']->w),r->T[board[i][j]-'a']->w={};
        
        Trie* newroot = r->T[board[i][j]-'a'];        
        vis[i][j] = 1;
        dfs(board, i+1,j,newroot);
        dfs(board, i-1,j,newroot);
        dfs(board, i,j+1,newroot);
        dfs(board, i,j-1,newroot);
        vis[i][j] = 0;
    }
};