class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while (x){
            ans = (ans * 10) + x %10;
            x/=10;
        }
        if (ans<INT_MIN) ans = 0;
        if (ans>INT_MAX) ans = 0;
        return ans;
    }
};