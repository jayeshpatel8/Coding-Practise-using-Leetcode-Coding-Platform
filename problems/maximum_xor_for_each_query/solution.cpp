class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        int nxor=0, mask = (1u << maximumBit)-1;
        for(auto i : nums){
             nxor ^=  i;
            ans[--n] = nxor  ^ mask;
        }
        return ans;
    }
};