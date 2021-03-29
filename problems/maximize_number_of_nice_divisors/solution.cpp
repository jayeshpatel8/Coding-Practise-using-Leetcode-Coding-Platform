class Solution {
public:
    int powermod(int n, int mod){
        uint64_t b=3, res=1;
        while(n>0){
            if (n & 1){
                res = (res * b) % mod;
                n--;
            }
            n>>=1;
            b = (b * b)% mod;
        }

        return res;
    }
    int maxNiceDivisors(int n) {
     uint64_t  cnt=1;
        int mod = 1e9 +7;
       
    
        if (n>4){
            int n3 = (n / 3);
            n =n %3;
            if (n == 1){
                cnt  =  powermod(n3-1,mod);    
                n= 4;
            }
            else{
                cnt  =  powermod(n3,mod);                
            }
        }
        if (n) cnt  = (n * cnt) % mod;
        return cnt;
    }
};