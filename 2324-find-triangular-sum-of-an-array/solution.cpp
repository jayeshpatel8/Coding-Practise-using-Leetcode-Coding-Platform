class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n  = nums.size();if (n ==1) return nums[0];
        vector<int> tmp(n);
        for (int i = 0; i<n; i++){
            for (int k=0; k<n-i-1; k++){
                tmp[k] = (nums[k] + nums[k+1]) % 10;
            }
            swap(nums,tmp);
        }
        return tmp[0];
    }
};
