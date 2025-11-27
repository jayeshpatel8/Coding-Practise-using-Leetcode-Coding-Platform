class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        using ll = long long;
        vector<ll> ksum(k,LONG_LONG_MAX/2);
        ll psum=0,maxSum=LONG_LONG_MIN;
        ksum[k-1]=0;

        for (int i=0; i<nums.size(); i++){
            psum += nums[i];
            maxSum= max(maxSum , psum - ksum[i%k]);
            ksum[i%k] = min(ksum[i%k], psum);
        }
        return maxSum;
    }
};
