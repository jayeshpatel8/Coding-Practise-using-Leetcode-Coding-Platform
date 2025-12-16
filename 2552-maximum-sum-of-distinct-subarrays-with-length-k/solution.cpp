class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        using ll = long long;
        unordered_map<int,int> f;
        ll ans = 0, sum=0;

        for (int i=0,j=0, distinct=0; i<nums.size(); i++){
            auto n = nums[i];
            sum += n;
            if (++f[n] == 1) distinct++;

        if (i - j + 1>= k){
                if( distinct == k)
                    ans=max(ans,sum);
                sum-=nums[j];         
                if (--f[nums[j++]] == 0) distinct--;       

            }
        }
        return ans;
    }
};
