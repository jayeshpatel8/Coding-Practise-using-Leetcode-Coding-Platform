class Solution {
public:
    int climbStairs(int n) {
        if (n<=3) return n;
        int p1=1, p2=1;
        for (int i =2; i<=n; i++){
            int c = p1+p2;
            p1=p2;
            p2=c;
        }
        return p2;
    }
};