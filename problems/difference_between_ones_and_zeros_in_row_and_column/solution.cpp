class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<int> R(M),C(N);
        int i=0;
        for (auto r : grid){
            int sum = 0;
            for (auto c : r)
                sum+= c?1:-1;
            R[i++]=sum;
        }
        i=0;
        for ( int c  = 0; c<N; c++){
            int sum = 0;
            for (auto r=0; r<M; r++)
                sum+=grid[r][c]?1:-1;
            C[c]=sum;
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