class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int M = grid.size(), N =grid[0].size();
        if (k >= M+N-2) return M+N-2;
        queue<array<int,3>> q;
        bool vis[M+1][N+1][k+2];
        memset(vis,0,sizeof(vis));
        q.push({0,0,k});
        int d=-1;        
        int r[5]={-1,0,1,0,-1};
        vis[0][0][k]=1;
        
        int dirs[5] = {-1,0,1,0,-1};
        while (!q.empty()){
            d++;
            int sz = q.size();
            
            while (sz-- > 0){
                auto [r,c,k1] = q.front(); q.pop();
              
                if (r == M-1 && c == N-1) return d;
                for (int i=0; i < 4; i++){
                    int r1 = r + dirs[i], c1 = c + dirs[i+1];                    
                    if (r1<0 || r1>=M || c1<0 || c1>=N  ) continue;
                    int k2 = k1 - grid[r1][c1];
                    if (k2 >= 0 && !vis[r1][c1][k2])
                        q.push({r1,c1,k2}),vis[r1][c1][k2]=1;
                }
            }
        }
        return -1;
    }
};