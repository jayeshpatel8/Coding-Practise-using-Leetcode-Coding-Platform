class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> rmax(nums.size());
        for (int i=nums.size()-1, m = INT_MIN; i>=0; i--){
            rmax[i] = m = max(m,nums[i]);
        }
        long long ans = 0, m = nums[0];
        for (int i=1; i<nums.size()-1; i++){
            ans = max(ans, (m - nums[i]) * rmax[i+1]);
            m = max<int>(m,nums[i]);
        }
        return ans;
    }
};