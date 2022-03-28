class Solution {
public:
    bool search(vector<int>& nums, int target) {

         return bs(nums,target,0,nums.size()-1);
    }
    bool bs(vector<int>& nums, int target, int l, int r){
        if (l>=r) return nums[l] == target;
        
        int m = (l + r) / 2;
        if (nums[m]==target) return true;
        else if (nums[l] == nums[r]){
            if (nums[l] == target) return true;
            else
                return bs(nums,target,l+1,r-1);
        }
        
        else if (nums[m]  <= nums[r]){
            if (target > nums[m] && target <= nums[r]){
                return bs(nums,target,m+1,r);
            }
            else
                return bs(nums,target,l,m-1);
        }
        else{
            if (target >= nums[l] && target < nums[m]){
                return bs(nums,target,l,m-1);
            }
            else
                return bs(nums,target,m+1,r);
        }
        return false;
    }
};