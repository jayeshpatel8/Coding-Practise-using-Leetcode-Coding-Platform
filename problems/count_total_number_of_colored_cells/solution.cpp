class Solution {
public:
    long long coloredCells(int n) {
         return 1 + 4  * ((n-1) *  (long long)n)/2;
        return 1 + 2LL * n * (n-1);
    }
};