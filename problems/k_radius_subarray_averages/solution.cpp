class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        if (k==0) return nums;
        vector<int> ans(nums.size(),-1);
        size_t  sum = 0;
        for (int i=0,j=k,len=2*k, sz = len+1; i<nums.size(); i++){
            sum += nums[i];
            
            if (i >= len){
                ans[j++] =sum/sz;
                sum -=nums[i-len];
            }
        }
        return ans;
    }
};