class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> setbit(31,0);
        vector<int> ans(nums.size());
        for (int i=nums.size()-1; i>=0; i--){
            for (int j=0; j<=30; j++){
                if ((1<<j) & nums[i]) 
                    setbit[j]=i;                
            }            
            ans[i]=(max(1,*max_element(begin(setbit),end(setbit))-i+1));
        }
        return ans;
    }
};