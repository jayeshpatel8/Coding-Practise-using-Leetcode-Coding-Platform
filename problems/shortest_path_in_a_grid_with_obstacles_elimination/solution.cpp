class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int M = grid.size(), N =grid[0].size();
        if (k >= M+N-2) return M+N-2;
        queue<array<int,3>> q;
        int vis[M+1][N+1][k+2];
        memset(vis,0,sizeof(vis));
        q.push({0,0,k});
        int d=-1;        
        int r[5]={-1,0,1,0,-1};
        vis[0][0][k]=1;
        while(!q.empty()){
            int sz = q.size();
            d++;
            while(sz--){
                auto i  = q.front(); 
                int x = i[0], y =i[1], k1=i[2];

                if (x == M-1 && y ==N-1) return d;

                for (int j=0; j<4; j++ )
                {
                    int x1 = x+r[j], y1= y+r[j+1],k2;
                    if (x1 < 0 || y1< 0 || x1>=M || y1>=N ) continue;
                    k2 = k1-grid[x1][y1];
                    if (k2 >=0 && !vis[x1][y1][k2] )     {                     
                            q.push({x1,y1,k2}),   vis[x1][y1][k2]=1;
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};