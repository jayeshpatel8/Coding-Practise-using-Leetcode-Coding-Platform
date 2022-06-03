class NumMatrix {
public:
    vector<vector<int>> psum;
    NumMatrix(vector<vector<int>>& matrix) {
        int M= matrix.size(), N = matrix[0].size();
        psum.resize(M + 1, vector<int> (N+1));
        
        for (int i=1; i<=M; i++){
            for (int j=1; j<=N; j++){
                psum [i][j] = matrix[i-1][j-1] + psum [i-1][j] + psum [i][j-1] - psum [i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return psum [r2+1][c2+1]  - psum [r1][c2+1] - psum [r2+1][c1] + psum [r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */