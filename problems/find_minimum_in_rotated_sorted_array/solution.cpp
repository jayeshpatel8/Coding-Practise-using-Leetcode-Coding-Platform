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
            if (l==m ? nums[l] <  nums[++m] : nums[l] <  nums[m]) 
                l=m;
            else
                r=m-1;
        }
        return nums[(r+1)%nums.size()];
    }
};