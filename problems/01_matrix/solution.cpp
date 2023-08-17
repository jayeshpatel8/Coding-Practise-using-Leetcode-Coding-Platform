

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        
        for (int i=0; i<M; i++){
            for ( int j=0;j<N; j++){
                if (mat[i][j]){
                    int ans =1e5;
                    if (i-1>=0)
                        ans = min(ans  , mat[i-1][j] );
                    if (j-1>=0)
                        ans = min(ans  , mat[i][j-1] );
                    mat[i][j] += ans ;
                }
            }
        }
        for (int i=M-1; i>=0; i--){
            for ( int j=N-1;j>=0; j--){
                if (mat[i][j]){
                    if (i+1<M)
                        mat[i][j] = min(mat[i][j], mat[i+1][j]+1);
                    if (j+1<N)
                        mat[i][j] = min(mat[i][j], mat[i][j+1]+1);
                }
            }
        }        
        return mat;
    }

};