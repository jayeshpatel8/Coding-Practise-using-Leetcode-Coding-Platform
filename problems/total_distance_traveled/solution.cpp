class Solution {
public:
    int distanceTraveled(int mt, int at) {
        for (int i=5; i<=mt ; i+=5)
            mt += at-- > 0;
        
        return 10 * mt;
    }
};