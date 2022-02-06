class Bitset {
public:
    vector<uint64_t> A;
    string ans ;
    int sz= 0 , total = 0,cnt=0;
    Bitset(int size) {
        total = size;
        sz = size/64 + ((size % 64) != 0);
        A.resize(sz);
        ans = string(total,'0');
    }
    
    void fix(int idx) {
        if (idx >=0 && idx <total){
            int i = idx / 64, j = idx %64;
            if ((A[i] & (1UL<<j)) == 0){
                A[i] |= (1UL<<j); cnt++;
            }
        }
    }
    
    void unfix(int idx) {
        if (idx >=0 && idx <total){
            int i = idx / 64, j = idx %64;
            if (A[i] & (1UL<<j) ){
                A[i] &= ~(1UL<<j); cnt--;
            }    
        }
    }
    
    void flip() {
        for (auto &i : A)
            i = ~i;
        cnt = total-cnt;
    }
    
    bool all() {
        return total ==  cnt;
    }
    
    bool one() {
        return cnt;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        
        int k=0;
        for (auto i : A){
            for (int j=0; j<64 && k<total; j++){
                if (i & (1UL<<j))
                    ans[k]= '1';
                else 
                    ans[k]='0';
                k++;
            }
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */