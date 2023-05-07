class Solution {
public:
int ans = 0;
    int minIncrements(int n, vector<int>& cost, int i=1) {
        if (2 * i > n) return cost[i-1];
        int l = minIncrements(n,cost,2*i), r = minIncrements(n,cost,2*i+1);
        ans += abs(l-r);
        return i==1? ans : cost[i-1] + max(l,r);
    }
};