class StockSpanner {
public:
    StockSpanner() {
        
    }
    vector<array<int,2>>  stack;
    int next(int price) {
        int ans = 1;
        while (!stack.empty() && stack.back()[0] <= price){
            ans +=  stack.back()[1]; stack.pop_back();
        }
        stack.push_back({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */