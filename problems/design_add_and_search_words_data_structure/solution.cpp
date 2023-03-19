class Trie{
    public:
    Trie * ch[26]={};
    bool w=false;
};
class WordDictionary {
public:
Trie root;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trie * r = &root;
        for (auto c : word){
            if (!r->ch[c-'a'])
                r->ch[c-'a']= new Trie;
            r = r->ch[c-'a'];
        }
        r->w=true;
    }
    bool search2(string & word, Trie * r, int i=0) {
        for (;i<word.size(); i++){
            auto c = word[i];
            if (c=='.'){
                for ( char ch='a'; ch<='z'; ch++){
                    if (!r->ch[ch-'a']) continue;
                    if (search2(word, r->ch[ch-'a'],i+1)){
                        return true;
                    }
                }
                return false;
            }
            if (!r->ch[c-'a'])
                return false;
            r = r->ch[c-'a'];
        }
        return r->w;        
    }
    bool search(string word) {
        Trie * r=&root;
        for (int i = 0;i<word.size(); i++){
            auto c = word[i];
            if (c=='.'){
                for ( char ch='a'; ch<='z'; ch++){
                    if (!r->ch[ch-'a']) continue;
                    if (search2(word, r->ch[ch-'a'],i+1)){
                        return true;
                    }
                }
                return false;
            }
            if (!r->ch[c-'a'])
                return false;
            r = r->ch[c-'a'];
        }
        return r->w;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */