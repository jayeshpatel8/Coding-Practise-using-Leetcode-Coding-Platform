class Solution {
public:
    
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        vector<int> po(nums.size()+1);
        int ans=0, mod = 1e9 + 7;
        po[0]=1;
        for (int i=1; i<=nums.size(); i++)
            po[i] = (po[i-1]*2) % mod;
        for ( int r=nums.size()-1,l=0; l<=r; )
        {
            if (nums[l] + nums[r] > target)
                r--;
            else
                ans = (ans + po[r - l++])%mod;            
        }
        return ans;
    }
};