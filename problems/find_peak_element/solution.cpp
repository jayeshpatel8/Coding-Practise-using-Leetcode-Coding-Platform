class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return 0;
        int peak=INT_MIN;
        if (nums[0] > nums[1]) peak=0;
        if (nums[n-2] < nums[n-1]) {
            if (peak != 0 || nums[n-1] > nums[0])
                peak=n-1 ;
        }
        for (int i=1; i< n-1; i++)
        {
            if (nums[i-1] > nums[i] || nums[i+1] > nums[i]) continue;
            else{
                if (peak == INT_MIN || nums[i] > nums[peak]) peak = i;
                i++;
            }
        }
        return peak;
    }
};