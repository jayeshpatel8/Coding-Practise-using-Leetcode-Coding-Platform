class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt=0, small=0;
        
        for (auto i : nums){
            cnt += i==target;
            small += i<target;
        }
        vector<int> ans(cnt);
        iota(begin(ans),end(ans),small);
        return ans;
    }
};