class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(),n = mat[0].size();
        vector<vector<int>> psum(m+1, vector<int>(n+1) ), ans(m, vector<int>(n) );
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                psum[i+1][j+1] = psum[i+1][j] + mat[i][j];
            }
        }
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int r1 =  max(0,i-k), r2 = min(m-1,i+k);
                int c1 =  max(0,j-k), c2 = min(n-1,j+k);
                int sum=0;
                for (  int r=r1; r<=r2; r++)
                    sum += psum[r+1][c2+1] - psum[r+1][c1];
                ans[i][j] = sum;
            }
        }
        return ans;
        
    }
};