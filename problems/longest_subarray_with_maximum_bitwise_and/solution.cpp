class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m = *max_element(begin(nums),end(nums)), ans = 1;
        for (int i=0, c=0; i<nums.size(); i++){
            if (nums[i]== m){
                ans = max(ans , ++c);
            }
            else c = 0;
        }
        return ans;
    }
};