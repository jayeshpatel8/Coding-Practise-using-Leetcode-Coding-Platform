class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans  , n = nums.size() ,max_sum=nums[0], min_sum=nums[0] ,total=0;
        for (int i=0, c1=0, c2=c1 ;i<n; i++){
            c1 = max(c1 + nums[i], nums[i]);
            max_sum = max(max_sum, c1);

            c2 = min(c2 + nums[i], nums[i]);
            min_sum = min(min_sum, c2);            
            total += nums[i];
        }   
        return max_sum <= 0 ? max_sum : max (total - min_sum, max_sum);
    }
};