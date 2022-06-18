class WordFilter {
public:
    struct Trie{
        Trie* ch[27]={};
        int ind=0;
    };
    Trie trie;
    WordFilter(vector<string>& words) {
        
        for (int i=0; i<words.size(); i++){            
            string w = words[i];
            string w1 = w + '{' + w;
            
            for(int j=0; j<=w.size(); j++){
                Trie * t = &trie;
                for (int k = j; k<w1.size(); k++){
                    if(!t->ch[w1[k]-'a'])
                        t->ch[w1[k]-'a']  = new Trie;
                    t = t->ch[w1[k]-'a'] ;
                    t->ind = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string w = suffix + '{' + prefix;
        
        auto * t = &trie;
        for (auto c : w){
            if (!t->ch[c-'a']) return -1;
            t = t->ch[c-'a'];            
        }
        return t->ind;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */