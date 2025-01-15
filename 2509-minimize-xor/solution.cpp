class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c1 =__builtin_popcount(num1);
        int c2 =__builtin_popcount(num2);
        int ans = num1;
        int c = c2-c1;

        if (c >= 0){
            for (int i=0; i<32 && c > 0; i++){
                if (ans & (1 << i)) continue;
                ans |= (1 << i);
                c--;
            }
        }
        else {
            for (int i=0; i<32 && c < 0; i++){
                if (ans & (1 << i)){
                    ans &= ~(1 << i);
                    c++;
                }
            }
        }
        return ans;
    }
};
