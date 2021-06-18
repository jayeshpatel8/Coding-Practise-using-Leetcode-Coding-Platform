class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l=0,r=0,n=0,c=0;
        
        while (r<nums.size()){
            if (nums[r] >= left && nums[r]<=right){
                n = r - l  + 1;
                c += r - l  + 1;
            }
            else if (nums[r] < left){
                c+=n;
            }
            else{
                n=0;
                l = r + 1;
            }
            r++;
        }
        return c;
    }
};