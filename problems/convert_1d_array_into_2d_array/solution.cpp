class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& ori, int m, int n) {
        int N = ori.size();
        if (N != m*n) return {};
        vector<vector<int>> ans (m,vector<int>(n)); 
        for (int i=0, k=0; i<m; i++){
            for(int j=0; j<n; j++)
                ans[i][j] = ori[k++];
        }
        return ans;
    }
};