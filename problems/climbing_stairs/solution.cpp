class Solution {
public:
    int climbStairs(int n) {        
        if (n<=3) return n?n:1;
        int res=3,prev=2;;
        for (int i=4; i<=n; i++)
        {
            int t=res;
            res += prev;
            prev=t;
        }
        return res;
    }
};

// 1 1 1 1 