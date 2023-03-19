class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> m;
        for (auto i : nums) m[i%k].push_back(i);
        vector<int> A;
        for (auto &[k,v]: m) {
            sort(begin(v),end(v));
            A.insert(end(A),begin(v),end(v));
        }
        int dp[21][2]={};
        function <int(int,int)> dfs = [&](int i, int last)-> int {
            if (i==A.size())return 1;
            auto ug = A[i] - A[last] == k;
            if (dp[i][ug]) return dp[i][ug];
            auto ans = dfs(i+1,last);
            if (!ug) ans += dfs(i+1,i);
            return dp[i][ug] = ans;

        };
        return dfs(0,A.size()-1)-1;
    }
};