class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 1;
        for (int i=2 , n = gcd(a,b); i<=n;i++){
            if ((a%i==0) && (b%i==0)) ans++;
        }
        return  ans;
    }
};