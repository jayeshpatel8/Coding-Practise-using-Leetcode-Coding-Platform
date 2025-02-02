
class Solution {
public:
    bool check(vector<int>& nums) {
        int start = nums[0], n = nums.size();
        int i=1;
        for (; i<n && nums[i-1] <= nums[i]; i++){
            ;
        }
        
        if (i<n && start < nums[i++]) return 0;
        
        for (; i<n && start >= nums[i] && nums[i-1] <= nums[i]; i++){
            ;
        }
        return i==n;
    }
};
