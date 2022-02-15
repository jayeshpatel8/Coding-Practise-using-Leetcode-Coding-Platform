class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        for (int i=0; i<M; i++){
            vector<int> a;
            for (int k=i, j=0; k<M && j<N; k++,j++){
                a.push_back(mat[k][j]);
            }
            sort(begin(a),end(a));
            for (int k=i, j=0,c=0; k<M && j<N; k++,j++){
                mat[k][j] = a[c++];
            }
        }
        for (int j=0; j<N; j++){
            vector<int> a;
            for (int k=j, i=0; i<M && k<N; k++,i++){
                a.push_back(mat[i][k]);
            }
            sort(begin(a),end(a));
            for (int k=j, i=0,c=0; i<M && k<N; k++,i++){
                mat[i][k] = a[c++];
            }
        }        
        return mat;
    }
};