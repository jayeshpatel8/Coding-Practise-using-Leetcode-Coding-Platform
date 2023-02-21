class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size(),  l = 0, r= N-1 ;
        while (l<r){
            int m = (l+r) / 2;
            if (m+1< N && nums[m]==nums[m+1]){
                if ((N-m)& 1){ //odd
                    l = m+1;
                }
                else
                    r=m-1;
            }
            else if (m-1 >=0  && nums[m]==nums[m-1]){
                if (m & 1){ //even
                    l=m+1;
                }
                else
                    r = m-1;
            }
            else return nums[m];
        }
        
        return nums[l];
    }
};