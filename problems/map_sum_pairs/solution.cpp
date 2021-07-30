class MapSum {
public:
    /** Initialize your data structure here. */
    struct trie{
        trie * ch[26] = {};
        int sum = 0;
    } root;
    unordered_map<string, int> keys;
    MapSum() {
    }
    
    void insert(string key, int val) {
        int diff = val - keys[key];
        keys[key] = val;
        auto p = &root;
        for (int i=0  ; i<key.size(); ++i){
            int ch = key[i]- 'a';
            if (!p->ch[ch])
                p->ch[ch] = new trie();
            p = p->ch[ch];
            p->sum +=diff;            
        }
    }
    
    int sum(string prefix) {
        trie * p = &root;
        for ( int i = 0; p && i < prefix.size(); ++i){
            p = p->ch[ prefix[i]-'a'];
        }
        return p ? p->sum : 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */