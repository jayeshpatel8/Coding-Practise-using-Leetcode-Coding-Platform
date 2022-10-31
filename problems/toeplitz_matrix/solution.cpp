class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        for (int i=0; i<M; i++){
            for (int r=i+1, j=1; r<M && j<N; r++,j++){
                if (matrix[i][0] != matrix[r][j]) return false;
            }
        }
        for (int c=1; c<N; c++){
            for (int r=1, j=c+1; j<N && r<M; j++ , r++){
                if (matrix[0][c] != matrix[r][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};