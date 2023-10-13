class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        for (int i=2; i<N; i++){
            cost[i] += min(cost[i-1],cost[i-2]);
        }
        return min(cost[N-1], cost[N-2]);
    }
};