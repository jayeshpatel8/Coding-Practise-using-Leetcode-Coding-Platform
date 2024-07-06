class Solution {
public:
    int passThePillow(int n, int time) {
        int div = time / (n-1) ,rem = time % (n-1);
        if (!rem) return (div & 1) ? n : 1;
        if (div & 1 ){
            return n - rem;
        }
        return rem  + 1;
    }
};
