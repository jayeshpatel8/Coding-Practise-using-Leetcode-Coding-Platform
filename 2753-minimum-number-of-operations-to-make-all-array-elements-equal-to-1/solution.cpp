class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> gcd_n(nums.size());
        for (auto i =0 ; i<nums.size(); i++) {
            if (nums[i]==1) return nums.size()-count(begin(nums),end(nums),1);
            
        }
        int ans=INT_MAX;
        for (int i=0,N = nums.size(); i<N; i++){
            int v=nums[i];
            for (int j=i+1; j<N; j++){
                v =gcd(v,nums[j]);
                if (v==1) ans=min(ans, N + (j-i) - 1);
            }
        }
        return ans==INT_MAX? -1 : ans;
    }
};
