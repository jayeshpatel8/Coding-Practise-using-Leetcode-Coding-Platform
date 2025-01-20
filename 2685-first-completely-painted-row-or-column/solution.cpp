class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int M = mat.size(), N= mat[0].size();
        vector<int> r(M),c(N);
        vector<array<int,2>> rc(M*N+1);
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++){
                rc[mat[i][j]]={i,j};
            }
        
        for (int i=0; i<M*N; i++){
            auto [i1,j1] = rc[arr[i]];
            if (++r[i1] == N) return i;
            if (++c[j1] == M) return i;
        }
        return 0;
    }
};
