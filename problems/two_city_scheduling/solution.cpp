class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(begin(costs),end(costs),[](auto &a, auto &b){
            return (a[0]-a[1]) < (b[0]-b[1]);
        });
        int sz = costs.size()/2, cost=0;
        for (int i=0; i<sz; i++)
            cost += costs[i][0] + costs[sz+i][1];
        
        return cost;
    }
};