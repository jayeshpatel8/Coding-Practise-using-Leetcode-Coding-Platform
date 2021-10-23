class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        
        while (l < r){
            // 3 2 1
            // 1 2 3
            // 2 1 3
            // 3 1 2
              int m = l + (r-l) / 2 ;
            if (nums[m] <  nums[r]) 
                r=m;
            else
                l=m+1;
        }
        return nums[l];
    }
};