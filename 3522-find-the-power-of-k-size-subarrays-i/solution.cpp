class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans,f(nums.size());
        f[0]=1;
        for  (int i=1; i <nums.size(); i++) f[i] = nums[i]== nums[i-1]+1 ? f[i-1]+1 : 1;
        for (int i=k-1; i<nums.size(); i++){
            ans.push_back(f[i] >=k ? nums[i] : -1);            
        }
        return ans;
    }
};
