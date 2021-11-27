class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size(), lp =1,rp=1;
        vector<int> ans(N);
        for( int i=N-1; i>=0; i--)
            ans[i] = rp, rp*=nums[i];
        for (int i=0; i<N; i++)
            ans[i] *= lp, lp *= nums[i];
        return ans;
    }
};