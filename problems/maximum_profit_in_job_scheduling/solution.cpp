class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> index(startTime.size());
        iota(begin(index), end(index),0);
        sort(begin(index), end(index), [&](auto i, auto j){return startTime[i] > startTime[j];});
        
        map<int,int> dp ;
        int ans = 0;
        for (  int i =0; i< index.size(); i++){
            auto it = dp.lower_bound(endTime[index[i]]);
            ans = max(ans, (it == end(dp)? 0 : it->second) + profit[index[i]]);
            dp[startTime[index[i]]]=ans;
        }
        return ans;
    }
};