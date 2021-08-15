class Solution {
public:
    int minNonZeroProduct(int p) {
        if (p==1) return 1;
        if(p==2) return 6;
        int mod = 1e9 + 7;
        long long n = (1ull <<p)-1;
        
        return (poewermod(n-1,n/2,mod) * (n%mod)) %mod;
    }
    uint64_t poewermod(uint64_t x, uint64_t y, int p){  // use square method to do exponentiation example: x^y =  (x^2)^(y/2)
       x %=p;
      if (x==0) return x;

      int64_t product=1;

      while (y>0){
        if (y&1){
           y--; // make it even
           product =(product* x) % p;       // mulMode needed if number > 32bit as product can be > 64it
        }
        y/=2;
        x=(x* x) % p;     //  do a squar til b becomes 1    
      } 
      return product;
    }                
};