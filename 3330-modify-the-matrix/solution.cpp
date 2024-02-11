class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        
        for (auto j=0; j<matrix[0].size();j++){
            int m=-1;
            for (int r=0; r<matrix.size(); r++)
                m = max(m,matrix[r][j]);
            for (int r=0; r<matrix.size(); r++)
                if (matrix[r][j]==-1) matrix[r][j]=m;
            
        }
        return matrix;
    }
};
