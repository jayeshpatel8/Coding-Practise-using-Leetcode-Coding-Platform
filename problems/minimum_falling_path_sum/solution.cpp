class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=1; i<n; i++){
            auto &ma =  matrix[i-1];
            for (int j=0; j<n; j++){
                matrix[i][j] +=  min({ j>0 ? ma[j-1] : INT_MAX,
                                    ma[j],
                                    j<n-1?ma[j+1]:INT_MAX});
                
            }
        }
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};