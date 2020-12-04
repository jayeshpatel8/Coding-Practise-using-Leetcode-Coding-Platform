#define KEY_MAX 3000
class LRUCache {
public:
    int LRU[KEY_MAX+1],prev[KEY_MAX+1],next[KEY_MAX+1];
    int head=0,tail=0,cap=0,max=0;
    void RemoveHead(void){
        int t = head;
        head= next[t];
        prev[head]=tail;
        next[tail]=head;
        
        LRU[t]=-1;
        next[t]=prev[t]=t;
    }
    void AddToTail(int key){
        tail[next]=key;
        prev[key]=tail;
        tail=key;
        
        next[tail]=head;
        prev[head]=tail;
    }
    void RemoveKey(int key){
        if (head == key)
            RemoveHead();
        else if (tail != key){
            int pr =prev[key], nx=next[key];
            next[pr]=nx;
            prev[nx]=pr;
            
            LRU[key]=-1;
            next[key]=prev[key]=key;
        }
    }
    LRUCache(int capacity) {
        max=capacity;
        for (int i=0; i<=KEY_MAX; i++){
            prev[i]=next[i]=i;
            LRU[i]=-1;
        }
    }
    
    int get(int key) {
        if (LRU[key]!= -1){  
          if (key != tail){
              int t = LRU[key];
              RemoveKey(key);
              AddToTail(key);  
              LRU[key]=t;
          }            
        }
        return LRU[key];
    }
    
    void put(int key, int value) {        
        if (LRU[key] == -1){
            // new
            if (cap<max){
                if (cap==0){
                    tail  = head= key;                        
                }
                else{
                    AddToTail(key);
                }
                cap++;
            }
            else{ //cap==full Add new Key
                  RemoveHead();
                  AddToTail(key);                                    
            }
        }
        else{       // update key
            if (key != tail){
                RemoveKey(key);
                AddToTail(key);
            }
        }    
        LRU[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

