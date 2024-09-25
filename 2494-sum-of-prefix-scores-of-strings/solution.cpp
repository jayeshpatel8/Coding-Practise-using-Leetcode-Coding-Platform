class Solution {
public:
    struct Trie{
      Trie * ch[26]={};
        int score=0;
    }T;
    void add(string& w){
        auto * r = &T;
        for (auto c : w) {
            if (!r->ch[c-'a'])
                r->ch[c-'a'] = new Trie();            
            r = r->ch[c-'a'];
            r->score++;            
        }
    }
    int getscore(string & w){
        auto * r = &T;
        int ans = 0;
        for (auto c : w) {
            r = r->ch[c-'a'];
            ans += r->score;
        }        
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        for (auto &w : words){
            add(w);
        }
        for (auto &w : words){
            ans.push_back(getscore(w));
        }
        return ans;
    }
};
