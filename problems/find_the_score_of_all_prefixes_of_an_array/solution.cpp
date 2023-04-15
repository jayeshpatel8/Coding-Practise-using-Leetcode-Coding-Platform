class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        long long sum = 0, m=0;
        for (auto i : nums){
            m=max((int)m, i);
            
            sum += i + m;
            ans.push_back(sum);
        }
        return ans;
    }
};