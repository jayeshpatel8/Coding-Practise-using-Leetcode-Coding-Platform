class StockSpanner {
public:
    vector<array<int,2>> st;
    int d=0;
    StockSpanner() {
        st.push_back({INT_MAX,0});
    }
    
    int next(int price) {
        ++d;
        while (st.back()[0] <= price) st.pop_back();
        auto ans  = d - st.back()[1];
        st.push_back({price,d});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */