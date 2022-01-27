class Solution {
public:
    int dirs[5]={-1,0,1,0,-1},M,N;
    vector<int> uf, size;
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        M =grid.size(), N = grid[0].size();
        uf.resize(M*N+1,-1);
        size.resize(M*N+1,1);
        
        for (auto & e : hits){
            int i = e[0] , j = e[1];
                if (grid[i][j])
                    grid[i][j] = 2;
        }

        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
                if (grid[i][j] == 1)
                    connect_around(i,j,grid);
 
        vector<int> ans(hits.size());
        int count_prev = size[find(0)];
        for (int h=hits.size()-1; h>= 0; h--){
            int i = hits[h][0] , j = hits[h][1];
            if (grid[i][j] != 2) continue;
            grid[i][j] = 1;
            connect_around(i,j,grid);
            int count = size[find(0)];
            ans[h] =max(0, count -count_prev -1);
            count_prev = count;
        }        
        return ans;
    }
    int find(int i){
        return uf[i] == -1? i : uf[i]  = find(uf[i]);
    }
    void connect(int i, int j){
        int pi = find(i), pj = find (j);
        if (pi != pj){
            if (size[pi] <= size[pj]){
                size[pj] += size[pi];
                uf[pi] = pj;
            }
            else{
                uf[pj] = pi;
                size[pi] += size[pj];
            }                
        }
    }
    void connect_around(int i, int j,vector<vector<int>>& grid){
        
        int n = i * N + (j+1);
        if (i==0) connect(0,n);
        for (int d=0; d<4; d++){
            int i1 = i +dirs[d]  , j1 = j + dirs[d+1];
            if (i1<0 || i1>=M || j1<0 || j1>= N || grid[i1][j1]!=1) continue;
            connect(n , i1*N+j1+1);
        }
        
    }
};