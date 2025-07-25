class Solution {
public:
    int maxSum(vector<int>& nums) {
        int f[101]={}, ans = 0;
        for (auto i : nums){
            if (i <=0 || f[i]) continue;
            f[i]=1; ans+=i;
        }
        return ans ? ans : *max_element(begin(nums),end(nums));
    }
};
