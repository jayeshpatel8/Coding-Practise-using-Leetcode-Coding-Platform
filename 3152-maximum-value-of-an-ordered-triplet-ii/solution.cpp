class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> r(nums.size()+1);
        for (int i=nums.size()-1; i>1;i--)
            r[i] = max(r[i+1], nums[i]);
        long long ans=  0;
        for (int i=1,m=nums[0]; i<nums.size()-1; i++){
            ans = max(ans, (m - nums[i]) * (long long) r[i+1]);
            m= max(m, nums[i]);
        }
        return ans;
    }
};
