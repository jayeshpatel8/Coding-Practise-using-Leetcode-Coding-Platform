class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
     int ans = 0;
        for (auto &i : accounts){
            ans= max(ans, accumulate(begin(i),end(i),0));
        }
        return ans;
    }
};