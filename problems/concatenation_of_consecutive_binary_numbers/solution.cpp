constexpr int MOD = 1e9 + 7;
class Solution {
public:
    
    int concatenatedBinary(int n) {
        uint64_t res = 1,shift=1;
        for (int i=2;i <=n;i++){
            while((1<<shift)<=i)shift++;
            res=(res << shift |i)% MOD;
        }
        return res ;
    }
};