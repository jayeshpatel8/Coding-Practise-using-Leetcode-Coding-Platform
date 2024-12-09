class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> psum(n+1);
        vector<bool> ans;
        for (auto i=1; i<n; i++) 
                psum[i] = psum[i-1]+(nums[i]%2 ==  nums[i-1]%2);
            
        for (auto q : queries){
            ans.push_back(psum[q[1]] -psum[q[0]] == 0);
        } 
        return ans;
    }
};
