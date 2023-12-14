class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<int> R(M),C(N);
        int i=0;
        for (auto i =0; i< M; i++){
            
            for (auto j =0; j< N; j++){
                auto c = grid[i][j];
                R[i] +=c?1:-1;
                C[j] +=c?1:-1;
            }            
        }
        vector<vector<int>> ans(M);
        for (auto r=0; r<M; r++){
            for ( int c  = 0; c<N; c++){
                ans[r].push_back(R[r]+C[c]);
            }
        }
        return ans;
    }
};
