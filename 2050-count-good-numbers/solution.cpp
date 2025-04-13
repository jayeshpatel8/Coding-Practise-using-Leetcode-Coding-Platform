class Solution {
public:
    int M = 1e9 +7;
    int countGoodNumbers(long long n) {
        return modp(5,(n+1)/2) * modp(4,n/2) % M;   
    }
    long long modp(long long x, long long y){
        if (y==0) return 1;
        auto p = modp(x,y/2);
        return p * p * (y%2 ? x: 1) % M;
    }
};
