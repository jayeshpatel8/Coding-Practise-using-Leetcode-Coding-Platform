class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int f[10001]={};
        for (int l=0,r=0,sum=0; r<nums.size(); r++){
            sum +=nums[r];
            while (f[nums[r]])
                sum -=nums[l], --f[nums[l++]];
            f[nums[r]]=1;
            ans = max(ans, sum);
        }
        return ans;
    }
};