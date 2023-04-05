class Solution {
public:
    int monkeyMove(int n) {
       long ans = 1, mod = 1e9 + 7, base = 2;
        while (n > 0){
            if (n & 1) 
                ans = (ans * base) % mod;
            base = (base * base) % mod;
            n >>=1;
        }
        return (ans - 2 + mod) %mod;
    }
};