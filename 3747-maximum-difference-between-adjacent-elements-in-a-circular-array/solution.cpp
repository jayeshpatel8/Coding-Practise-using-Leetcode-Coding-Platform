class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=0, N=nums.size();
        for (int i=0; i<nums.size();i++){
            ans= max(abs(nums[i]-nums[(i+1)%N]), ans);
        }
        return ans;
    }
};
