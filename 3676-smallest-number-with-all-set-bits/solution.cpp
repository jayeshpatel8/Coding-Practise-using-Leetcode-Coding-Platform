class Solution {
public:
    int smallestNumber(int n) {
        for (int i=10,f=0; i>=0; i--){
            if (n & (1 <<i)){
                f=1;
            }
            else if (f)
                n |= 1<<i;
        }
        return n;
    }
};
