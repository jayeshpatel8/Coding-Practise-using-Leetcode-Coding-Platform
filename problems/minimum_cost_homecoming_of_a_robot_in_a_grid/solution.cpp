class Solution {
public:
    int minCost(vector<int>& start, vector<int>& home, vector<int>& rowCosts, vector<int>& colCosts) {
        
        int ans = 0 ;
        
        for (int dir= start[0] < home[0] ? 1 : -1, i = start[0]; i != home[0]; i+=dir )
            ans += rowCosts[i+dir];
        for (int dir= start[1] < home[1] ? 1 : -1, i = start[1]; i != home[1]; i+=dir )
            ans += colCosts[i+dir];
        return ans;
    }
};