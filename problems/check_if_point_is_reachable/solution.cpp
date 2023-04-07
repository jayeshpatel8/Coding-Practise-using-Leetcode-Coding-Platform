class Solution {
public:
    bool isReachable(int x, int y) {
        int v = gcd(x,y);

        return (v & (v-1))==0;
    }
};