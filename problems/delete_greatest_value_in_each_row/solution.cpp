class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto &v : grid) sort(begin(v),end(v));
        int M = grid.size(),N =grid[0].size(),ret=0;
        for (int j=0; j<N; j++){
            int m=-1;
            for (auto i =0; i<M; i++)
                m=max(m,grid[i][j]);
            ret+=m;            
        }
        return ret;
    }
};