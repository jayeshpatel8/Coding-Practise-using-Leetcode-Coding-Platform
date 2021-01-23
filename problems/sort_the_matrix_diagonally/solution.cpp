class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int N=mat.size() , C= mat[0].size() ;
        unordered_map<int, deque<int>>M(C+N);
        
        for (int i=0; i<N ; i++){
            for (int j=0; j  <C; j++){
                int d =  C+i-   j  ;
                {
                    M[d].push_back(mat[i][j]);                                     
                }
            }
        }
        for (int i=1; i<C+N; i++ ) sort(M[i].begin(), M[i].end());
        for (int i=0; i<N ; i++){
            for (int j=0; j  <C; j++){
                int d =  C+i-   j  ;
                mat[i][j] = M[d].front(); M[d].pop_front();
            }
        }
        return mat;
    }
};