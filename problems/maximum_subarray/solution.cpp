class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, m = INT_MIN;
        
        for (auto i : nums){
            cur = max(cur+i, i);
            m = max ( m, cur);
        }
        return m;
    }
};