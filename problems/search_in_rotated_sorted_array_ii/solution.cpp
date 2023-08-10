class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l =  0, r=  nums.size()-1;
        while (l<=r){
            int m= (l+r)/2;
            if (nums[m]==target) return true;
            if (nums[l]==nums[r]) r--;
            else if (nums[l]<= nums[m] && nums[m]<nums[r]){
                 if (target < nums[l] || target > nums[r] )                 
                 return false;
                if (target < nums[m] ) r=m-1;
                else l=m+1;
            }
            else if (nums[l]<= nums[m] && nums[m]>nums[r]){
                if (target >= nums[l] && target < nums[m])
                    r=m-1;
                else if (target > nums[m] || target <= nums[r])
                    l=m+1;
                else return false;
            }
            else //if (nums[m] < nums[r] && nums[l] >= nums[m])
            {
                if (target > nums[m] && target <= nums[r])
                    l=m+1;
                else if (target >= nums[l] || target < nums[m])
                    r=m-1;
                else return false;
            }
        }
        return false;
    }
};