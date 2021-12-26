class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long> ans(arr.size()) ,dp(arr.size());
        unordered_map<int,pair<int,int>> m,m1;
        //for (int i=0; i<arr.size(); i++) m[arr[i]].push_back(i);
        for (int i=0; i<arr.size(); i++){
            int n = arr[i];
            if (m.count(n)) {
                auto &[id, cnt] = m[n];
                ans[i] += ans[id]  +  cnt++ * (i - id);
                id= i;
            }
            else
                m[n] = {i,1};

        }
        for (int i=arr.size()-1; i>=0; i--){
            int n = arr[i];
            if (m1.count(n)) {
                auto &[id, cnt] = m1[n];
                dp[i] += dp[id]  +  cnt++ * (id-i);
                ans[i] += dp[i];
                id= i;
            }
            else
                m1[n] = {i,1};

        }      
        return ans;
    }
};