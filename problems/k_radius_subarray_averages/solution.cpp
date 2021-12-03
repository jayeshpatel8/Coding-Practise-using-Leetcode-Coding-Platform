class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) return nums;
        long sum = 0;
        int i=0 , n = 2 * k + 1, N = nums.size();
        vector<int> ans(N,-1);
        for (; i<n && i<N; i++)
            sum+=nums[i];
        
        if (i==n) ans[i-k-1] = sum / n;
        
        for(; i<N; i++){
            sum+=nums[i]-nums[i-n];
            ans[i-k] = (sum / n);
        }
        return ans;
    }
};