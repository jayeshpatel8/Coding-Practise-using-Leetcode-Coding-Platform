
class MapSum {
        unordered_map<char ,  MapSum*> n;
    bool e;
    int v;
public:
    /** Initialize your data structure here. */
    MapSum() {
        n.clear();
        e=0;
        v=0;
    }
    
  
    void insert(string word, int val) {
        MapSum *t1=this;
    
        if (word.empty())
         return;
        if (n.empty())
        {
            //root node empty
            for(auto c1: word){
                auto *n1 = new MapSum();
                t1->n.emplace(c1,n1);
                t1=n1;
            }
            t1->v=val;
            t1->e=true;
            return;
        }
       size_t len=word.length();
        for(auto c1 : word)
        {
            auto got  = t1->n.find(c1);
            len--;
            if( got == t1->n.end())
            {
                auto *n1 = new MapSum();
                t1->n.emplace(c1,n1);
                t1=n1;
                continue;
            }
            else  

                t1=got->second;

        }
        t1->v=val;t1->e=true;
    }
        int mapsum(MapSum * t1)
                {
                    int sum1=0;
                    
                    for(auto it = t1->n.begin();it!=t1->n.end();++it)
                    {
                        sum1 +=  mapsum((it->second));
                    }
                    sum1+=(t1)->v;
                    return sum1;
                        
                }
    int sum(string prefix) {
              MapSum *t1=this;
        
        if (prefix.empty()|| n.empty() )
             return 0;
        size_t s = prefix.length();
        for(auto c1 : prefix)
        {
            s--;
            auto got  = t1->n.find(c1);
            if( got == t1->n.end())
            {
                return 0;
            }
            else if(0==s)
            {
                return mapsum(got->second);
            }
            else
                t1=got->second;

        }
        return 0;   
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */