class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& ori, int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n));
        if ((m*n)  != ori.size())return {};
        for ( int i =0,r=0; i<ori.size(); i+=n,r++){
            for (int j=0; j<n; j++)
                ans[r][j] = ori[i+j];
        }
        return ans;
    }
};
