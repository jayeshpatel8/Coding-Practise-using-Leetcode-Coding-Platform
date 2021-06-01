class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
     vector<int> dp(1<<n,INT_MAX);
        return minXsum(nums1, nums2, dp, 0, 0);

    }
    int minXsum(vector<int>& nums1, vector<int>& nums2,  vector<int> &dp, int i, int mask){
        int  n = nums1.size();
        if (i >= n) return 0;
        if(dp[mask] != INT_MAX) return dp[mask];
        for (int j=0; j<n; j++){
            if ((mask & (1 << j)) == 0){
                dp[mask] = min(dp[mask], (nums1[i] ^ nums2[j]) + minXsum(nums1, nums2, dp, i+1, mask + (1 << j)) );
            }
        }
        return dp[mask];
    }
    
};