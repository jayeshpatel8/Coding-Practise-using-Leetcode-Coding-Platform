class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int N=nums.size();
        vector<int> ans(2*N);
        for (int i=0;i <N; i++) ans[i]=ans[i+N]=nums[i];
        return ans;
    }
};