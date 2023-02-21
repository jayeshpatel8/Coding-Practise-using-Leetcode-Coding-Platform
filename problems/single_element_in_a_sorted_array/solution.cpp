class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size(),  l = 0, r= N-1 ;
        while (l<r){
            int m = (l+r) / 2;
            if (((m&1) && nums[m]==nums[m-1]) || ((m&1)==0  && nums[m]==nums[m+1]))
                l = m+1;

            else
                r=m;

        }
        
        return nums[l];
    }
};