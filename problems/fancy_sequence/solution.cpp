#define mod (1000000000+7)
class Fancy {
    vector<long> v, add,mul;
     long idx,ad=0,ml=1;
 
public:
    Fancy() {
        idx=0;

    }
    // x + a ) * b == (x * b *d + a*b+ c * d
    void append(int val) {
        v.push_back(val);    
        //cout << "append: " << ad << "," << ml << endl;
            add.push_back(ad);
            mul.push_back(ml);

       
        idx++;
    }
    
    void addAll(int inc) {
        ad = (ad+inc)%mod;
       // add[idx-1] = (add[idx-1] +inc  );
    }
    
    void multAll(int m) {
        ml =(ml *m)%mod;
        ad = (ad *m ) % mod;
    }
    int modPow(int x, int y) {
    unsigned long tot = 1, p = x;
    for (; y; y >>= 1) {
        if (y & 1)
            tot = (tot * p) % mod;
        p = (p * p) % mod;
    }
    return tot;
    }
    int getIndex(int id) {
        if (id >= v.size()) return -1;
        
       long m = ml * modPow(mul[id],mod-2 ) % mod;
        return (m* (mod +v[id] -add[id]) + ad ) % mod;

    }
    // add 0 3 6 9  18
    // mul 1 1 2 2  4
    // 0   2      
    // 1     7
    // 2          10
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */