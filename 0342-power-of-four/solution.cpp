class Solution {
public:
    bool isPowerOfFour(int n) {
        int mask=0;
        for ( int i=0; i<32; i+=2)
            mask |= 1<<i;
        return (n > 0) && (n & n-1) == 0 && ((n | mask)  == mask);
    }
};
