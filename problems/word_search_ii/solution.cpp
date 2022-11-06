class Solution {
public:
struct   Trie{
    Trie * ch[26]={};
    bool word=false;
}root;;
 int vis[12][12]={};
    void insert(vector<string>& words){
        for (auto s : words){            
            Trie * r = &root;
            for (auto ch : s){
                int c = ch-'a';
              if(!r->ch[c])  
                r->ch[c] = new Trie;
              r = r->ch[c];
            }        
            r->word = true;            
        }
    }
    vector<string> ans;
    string s;
    int M, N;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        M = board.size(), N = board[0].size();
        insert(words);
        for (auto i = 0; i<M; i++){
            for (int j = 0; j < N; j++){
                    dfs(board,i,j,s,&root);
            }
        }
        return ans;
    }
    int dirs [5] = {-1,0,1,0,-1};
    void dfs(vector<vector<char>>& board, int r, int c, string & res , Trie *tr){
        if (tr->word) { tr->word=false; ans.push_back(res);}
        if ( r >= M || r < 0 || c < 0 || c >= N || vis[r][c] ) return;
        
        
        auto ch  = board[r][c]-'a';
        if (tr->ch[ch]){
            res.push_back(ch+'a');
            vis[r][c]=true;
                for (int d = 0; d <4; d++)
                    dfs(board,r+dirs[d],c+dirs[d+1],res,tr->ch[ch]);
            vis[r][c]=false;
            res.pop_back();
        }
    }
};