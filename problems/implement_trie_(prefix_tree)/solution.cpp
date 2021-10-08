class Trie {
    Trie * t[26]={};
    bool w=false;
public:
    Trie() {
        
    }
    
    void insert(string word) {        
        Trie *root = this;
        for ( auto c : word){
            if (root->t[c-'a'] == NULL){
                root->t[c-'a'] = new Trie;
            }
            root= root->t[c-'a'];
        }
        root->w=true;
    }
    
    bool search(string word) {
        Trie *root = this;
        for ( auto c : word){
            if (root->t[c-'a'] == NULL){
                return false;
            }
            root= root->t[c-'a'];
        }
        return root->w==true;
        
    }
    
    bool startsWith(string word) {
        Trie *root = this;
        for ( auto c : word){
            if (root->t[c-'a'] == NULL){
                return false;
            }
            root= root->t[c-'a'];
        }
         return true;
                
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */