class Solution {
public:
    struct Trie{
        Trie * ch[26]={};
        string s;
    };
    Trie trie;
    void insert(string & s){
        Trie *t = &trie;
        for (auto c : s){
            if (!t->ch[c-'a'])
                t->ch[c-'a'] = new Trie;
            t = t->ch[c-'a'];
        }
         t->s = s;
    }
    void dfs(Trie *root, int len, vector<string> &out){
        if (out.size()==len || !root) return;
        if (!root->s.empty()) out.push_back(root->s);
        for (int c = 'a'; len &&c<='z'; c++){
            dfs(root->ch[c-'a'],len,out);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for (auto s : products)
            insert(s);
        vector<vector<string>> ans;
         Trie *t  = &trie;  
        vector<string> prev;
        for (auto c : searchWord){
            if (t && t->ch[c-'a']){
                t=t->ch[c-'a'];                    
                vector<string> a;
                dfs(t,3,a);
                ans.push_back(a);
                prev=a;
            }
            else{
                t=NULL;
                ans.push_back(vector<string>());
                

           }
        }
        return ans;
    }
};