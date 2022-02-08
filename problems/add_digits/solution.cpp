class Solution {
public:
    int addDigits(int n) {
        while(n > 9){
            int s = 0;
            while (n){
                s += n%10;
                n /=10;
            }       
            n = s;
        }
        return n;
    }
};