class StockPrice {
public:
    map<int,int> p,mi;
    //int cur=0;
    StockPrice() {
        
    }
    
    void update(int t, int price) {
        if (p.count(t)){
            if(mi[p[t]]-- == 1 ) mi.erase(p[t]) ;            
        }
        p[t]=price;
        mi[price]++;
    }
    
    int current() {
        return p.rbegin()->second;   
    }
    
    int maximum() {
        return mi.rbegin()->first; 
    }
    
    int minimum() {
        return mi.begin()->first; 
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */