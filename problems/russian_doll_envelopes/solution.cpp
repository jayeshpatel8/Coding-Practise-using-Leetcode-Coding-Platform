class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) {
        int n = en.size(), ma=0;
        vector<int> dp;
        
        sort(begin(en), end(en), [](auto &a, auto &b){ return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
        dp.push_back(en[0][1]);
        for (int i=1; i<n; i++){
            auto j = lower_bound(begin(dp),end(dp),en[i][1]);
            if (j == end(dp))
                dp.push_back(en[i][1]);
            else //if (*j > en[i][1])
                *j = en[i][1];                
        }
        return dp.size();
    }
};