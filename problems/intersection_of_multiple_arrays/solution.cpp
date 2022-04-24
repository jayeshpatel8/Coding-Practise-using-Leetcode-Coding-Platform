class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int cnt[1001]={};
        for (auto &i : nums)
            for (auto j : i)
                cnt[j]++;
        vector<int>  ans;
        for (int i=1; i<1001; i++)
            if (cnt[i]== nums.size())
                ans.push_back(i);
        return ans;
    }
};