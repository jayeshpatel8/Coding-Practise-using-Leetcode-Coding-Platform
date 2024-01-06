class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> idx(profit.size());
        iota(begin(idx),end(idx),0);
        sort(begin(idx),end(idx),[&](auto a, auto b){ return startTime[a] > startTime[b];});
        int ans =0; 
        map<int,int> dp;
        for (int i=0; i<profit.size(); i++){
            auto index = idx[i];
            auto start = startTime[index];
            auto it = dp.lower_bound(endTime[index]);
            ans = max(ans, profit[index] + (it == end(dp) ? 0 : it->second));
            dp[start] = ans;
        }
        return ans;
    }
};
