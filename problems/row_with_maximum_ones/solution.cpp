class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2);
        for (auto r=0; r< mat.size(); r++){
            int c = accumulate(begin(mat[r]),end(mat[r]),0);
            if (c > ans[1]) {
                ans = {r,c};
            }
        }
        return ans;
    }
};