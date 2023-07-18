class LRUCache {
public:
    map<int,int> lru;
    unordered_map<int,array<int,2>> k;
    int c = 0;
    long cnt=0;
    LRUCache(int capacity) {
        c= capacity;
    }
    
    int get(int key) {
        if (lru.count(k[key][0])){
            lru.erase(k[key][0]);
            k[key][0]=++cnt;
            lru[cnt]=key;
            return k[key][1];
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if (lru.count(k[key][0]) )
            lru.erase(k[key][0]);
        k[key][0]=++cnt;
        k[key][1]=value;
        lru[cnt]=key;            
        
        if (lru.size() > c){
            lru.erase(begin(lru));
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */