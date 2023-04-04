class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        vector<int> dp(nums.size());
        long long ans = 0;
        for (int k=2; k<nums.size(); k++){
            int small = 0;
            for (int j=0; j<k; j++){
                if (nums[k] > nums[j]){
                    small++;
                    ans += dp[j];
                }
                else
                    dp[j]+=small;
            }
        }   
        return ans;
    }
};