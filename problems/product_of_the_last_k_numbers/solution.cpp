class ProductOfNumbers {
public:
    vector<int> p;
    int cur=1  ,t=1 ,z=0;
    ProductOfNumbers() {
        p.push_back(1);
    }
    
    void add(int num) {
        t++;
        if (num == 0){
            cur=1; z= t -1;    
        }
        else 
            cur *=num;
        p.push_back(cur);
    }
    
    int getProduct(int k) {
        int start = t-k;
        if (start <= z) return 0;
        return cur / p[t-k -1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */