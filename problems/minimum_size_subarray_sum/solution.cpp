class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        for (int i=0,j=0,s=0; i<nums.size(); i++){
             s+= nums[i];
             while (s >= target) 
                ans =  min(ans, i-j+1),s -= nums[j++];
        }
        return ans==INT_MAX ? 0 : ans;
    }
};