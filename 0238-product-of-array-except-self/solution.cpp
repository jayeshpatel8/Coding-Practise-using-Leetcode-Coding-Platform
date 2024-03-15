class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        for (int i=0,m=1; i<n; i++){
            ans[i] *=m;
            m *= nums[i];
        }
        for (int i=n-1,m=1; i>=0; i--){
            ans[i] *=m;
            m *= nums[i];
        }   
        return ans;     
    }
};
