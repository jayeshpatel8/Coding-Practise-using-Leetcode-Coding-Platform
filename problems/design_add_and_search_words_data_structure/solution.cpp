class WordDictionary {
public:
    class Trie{
      public:
        Trie * ch[26]={};
        bool w=false;
    };
    Trie root;

    bool search(Trie* root1, string& w, int i = 0){
        Trie *r = root1;
        for (; i<w.size(); i++){
            int ch = w[i]- 'a';
            if (w[i] == '.'){
                for (int j=0;j<26;j++)
                    if (r->ch[j] && search(r->ch[j], w, i+1))
                            return true;
                return false;
            }
            else if (r->ch[ch]) 
                r = r->ch[ch];
            else
                return  false;                        
        }
        return r->w==true;
    }
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trie *r = &root;
        for (auto c : word){
            int ch = c- 'a';
            if (!r->ch[ch]) 
                r->ch[ch] = new Trie;
            r = r->ch[ch];
        }
        r->w=true;
    }
    
    bool search(string word) {
        return search(&root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */