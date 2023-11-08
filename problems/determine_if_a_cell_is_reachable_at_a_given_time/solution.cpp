class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int _max = max(abs(sx-fx) , abs(sy-fy));
        return _max==0 ? t!=1: t>=_max;
    }
};