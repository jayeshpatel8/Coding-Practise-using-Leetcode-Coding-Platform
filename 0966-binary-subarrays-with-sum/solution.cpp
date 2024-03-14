class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return maxsum(nums,goal)   - maxsum(nums,goal-1);
    }
    int maxsum(vector<int> nums, int goal){
        int sum = 0, cnt = 0;
        for (int i=0,j=0; i<nums.size(); i++){
            sum += nums[i];
            while (j<=i && sum > goal) {
                sum-=nums[j++];
            }
            cnt += i-j+1;
        }
        return cnt;
    }
};
