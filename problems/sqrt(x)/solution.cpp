
    class Solution {
public:
    int mySqrt(int x) {
        //newton    1/2 (xn+a/xn)
        if (x<4) return x?1:0;
        int xn=x/2;
        while(xn>x/xn) xn = (xn+x/xn)/2;
        return xn;
    }
};