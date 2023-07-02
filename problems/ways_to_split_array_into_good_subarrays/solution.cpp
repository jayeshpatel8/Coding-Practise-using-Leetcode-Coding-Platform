class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long ans = 0, mod= 1e9+7;
        for (int i=0,j=-1; i<nums.size(); i++){
            if (nums[i])
            {
                if (j==-1) ans=1;
                else
                    ans =  (ans * (i-j) )%mod;
                
                j=i;
            }
        }
        return ans;
    }
};