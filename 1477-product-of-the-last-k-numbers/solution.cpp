class ProductOfNumbers {
public:
    vector<int> prod;
    int sz;
    ProductOfNumbers() {
        sz = 0;
    }
    
    void add(int num) {
        if (num==0) {
            prod.clear();sz=0;
            return;
        }
        if (!prod.empty())
            num *= prod.back();
        prod.push_back(num);
        sz++;
    }
    
    int getProduct(int k) {
        if (k> sz) return 0;
        return prod.back() /  (sz-k-1 < 0 ? 1 : prod[sz-k-1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
