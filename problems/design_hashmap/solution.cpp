class MyHashMap {
    const int M = 1000;
    vector<vector<pair<int,int>>> kv;
public:
    /** Initialize your data structure here. */
    MyHashMap() {        
        kv.resize(1000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int h=key%M;
        for(auto & i :  kv[h]){
            if(i.first == key) {i.second = value;return;}
        }        
        kv[h].push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h=key%M;
        for(auto & i :  kv[h]){
            if(i.first == key) return i.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h=key%M;
        for(auto it=kv[h].begin(); it!=kv[h].end(); it++){
            if(it->first == key) {kv[h].erase(it); return;}
        }        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */