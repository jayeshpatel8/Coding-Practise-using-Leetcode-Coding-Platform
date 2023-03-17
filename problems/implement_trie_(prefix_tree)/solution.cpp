struct Tr{
    Tr * t[26] = {nullptr};
    bool w=false;

};
class Trie {
public:
struct Tr root;
    Trie() {
        
    }
    
    void insert(string word) {
        auto * r =  &root;
        for (auto c : word){
            if (!r->t[c-'a']){
                r->t[c-'a']=new Tr();
            }
            r = r->t[c-'a'];
        }
        r->w=true;
    }
    
    bool search(string word) {
        auto * r =  &root;
        for (auto c : word){
            if (!r->t[c-'a']){
                return false;
            }
            r = r->t[c-'a'];
        }
        return r->w;        
    }
    
    bool startsWith(string prefix) {
        auto * r =  &root;
        bool ans = false;
        for (auto c : prefix){
            if (!r->t[c-'a']){
                return false;
            }
            r = r->t[c-'a'];            
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