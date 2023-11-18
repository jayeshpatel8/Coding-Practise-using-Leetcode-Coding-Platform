class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
         long i=0,j=0, n = nums.size(), sum=0;
        sort(nums.begin(), nums.end());
        for (; j<n; j++){
            sum +=nums[j];
            if ( (j-i+1 ) * nums[j] - sum > k ) sum -= nums[i++];
        }
        return j-i;
    }
};
