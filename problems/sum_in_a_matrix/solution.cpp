class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ret = 0;
        for (auto &i : nums)
            sort(begin(i),end(i));
        int M = nums.size(), N = nums[0].size();
        for (int j=N-1; j>=0; j--){
            int m=0;
            for (int i=0; i<M; i++)
                m = max(m,nums[i][j]);
            ret += m;
        }
        return ret;
    }
};