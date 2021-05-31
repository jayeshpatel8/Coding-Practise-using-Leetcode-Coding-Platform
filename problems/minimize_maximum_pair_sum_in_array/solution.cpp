class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0, r = nums.size()-1;
        int ans = 0;
        
        //[3,5,2,3]
        // 2,3,3,5
        while( l < r){
            ans  = max (ans, nums[l++]+nums[r--]);
        }
        return ans;
    }
};