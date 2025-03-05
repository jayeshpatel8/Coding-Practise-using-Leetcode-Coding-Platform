class Solution {
public:
    long long coloredCells(int n) {
        // 1 + 4*1 + 4*2 + 4*3
        long long ans = 1;
        if (n >1 ) {
            ans += 2ULL * ((long long)n * (n-1));
        }
        return ans;
    }
};
