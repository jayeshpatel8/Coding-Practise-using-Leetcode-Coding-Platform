class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> r(m),c(n);
        for (auto i=0; i<m; i++)
            for (auto j=0; j<n; j++)
                if (matrix[i][j] == 0){
                    r[i]=c[j]=1;
                }
        for (auto i=0; i<m; i++)
            for (auto j=0; j<n; j++)
                if (r[i] || c[j])
                    matrix[i][j] = 0;
    }
};
