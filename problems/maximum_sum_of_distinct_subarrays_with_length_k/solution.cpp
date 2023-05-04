class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int> f(100001);
        long long ans =0, sum = 0 ;
        int dup = 0;
        for (int i=0,j=-1; i<nums.size(); i++){
            sum += nums[i];
            if (++f[nums[i]] == 2) dup++;
            
            if (i-j>=k){
                if (dup==0) ans = max(ans,sum);
                sum -= nums[++j];
                if (--f[nums[j]] == 1) dup--;
            }

        }
        return ans;
    }
};