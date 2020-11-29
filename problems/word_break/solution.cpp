class Solution {
public:
    class Trie{
        public:
            bool w;
            Trie * next[26]; 
        Trie(){
            w = false;
            for (int i =0; i<26; i++)
                next[i] = 0;
        }
    };
    
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie * trie = new Trie(),*t;
        
        for (auto & w : wordDict){
            t =trie;
            for  (auto & c : w){
                int ch = c-'a';
                if (!t->next[ch])
                    t->next[ch]=new Trie();
                t=t->next[ch];
            }
            t->w=true;
        }
        int n= s.length();
        vector<int> wordEnd(n+1,0);
        wordEnd[0]=1;
        for (int i=0; i<n; i++){
            if (wordEnd[i]==0) continue;
            t = trie;
            int j=i;
            while (j<n && t->next[s[j]-'a']){
                t = t->next[s[j++]-'a'];
                if (t->w) wordEnd[j]=true;
            }
            if (wordEnd[n]) return true;
        }
        return false;
    }
};