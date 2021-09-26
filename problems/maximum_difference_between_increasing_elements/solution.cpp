class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=0, prevm=nums[0];
        
        for ( int i=1; i<nums.size();i++){
            int n  =nums[i];
            ans = max(ans , n - prevm);
            prevm = min(prevm, n);
        }
        return ans <= 0 ? -1 :ans;        
    }
};