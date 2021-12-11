class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9 + 7 , lcm = a / gcd(a,b) *b;
        long l = 0, r = (long)n * min(a,b);
        
        while(l < r){
            long m = l + (r - l) / 2;
            
            if ( m/a + m/b - m/lcm < n)
                l = m + 1;
            else
                r = m;
        }
        return l%mod;
    }
    int gcd(int x, int y){
        if(x==0) return y;
        return gcd(y%x,x);
    }
};
/*

2 2 5
2 3 5

a: 20 40
b: 30 60

lcm : 60 120


*/