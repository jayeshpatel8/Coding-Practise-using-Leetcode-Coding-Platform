class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        // all fires block by wall and able to reach 10^9
        // cant reach at all -1
        // minutes
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> fires(m,vector<int>(n,1e6));
        queue<array<int,2>> q;
       for (int i=0; i<m; i++)
            for (int j=0; j<n; j++){
                if (grid[i][j] ==1){
                    q.push({i,j});
                    fires[i][j]=0;
                }
                else if (grid[i][j] ==2)
                    fires[i][j]=0;
            }
        int dirs[] = {0,-1,0,1,0};
        int cnt = 0;
        while (!q.empty()){
            int sz = q.size();
            ++cnt;
            while (sz-- >  0){
                auto [r,c] = q.front(); q.pop();
                for (int i =0; i<4; i++){
                    int r1 = r + dirs[i], c1= c + dirs[i+1];
                    if (r1<0|| c1<0 || r1>=m || c1>=n || fires[r1][c1] <= fires[r][c]+1) continue;
                    fires[r1][c1] = fires[r][c]+1;
                    q.push({r1,c1});
                }
            }
        }

        auto bfs  = [&]( int t){
            queue<array<int,2>> q;
            q.push({0,0});
            vector<bool> vis(m*n);
            vis[0]=1;
            while (!q.empty()){
                int sz = q.size();
                ++t;
                
                while (sz-- >  0){
                    auto [r,c] = q.front(); q.pop();
                    for (int i = 0; i<4; i++){
                        int r1 = r + dirs[i], c1= c + dirs[i+1];
                        if (r1<0|| c1<0 || r1>=m || c1>=n || vis[r1*n+c1] ) continue;
                        vis[r1*n+c1]=1;
                        if (r1==m-1 && c1==n-1){
                            return fires[r1][c1] >= t;
                        }
                        if (fires[r1][c1] <= t) continue;
                        q.push({r1,c1});
                    }
                }
            }            
            return false;
        };    
        int l=-1, r= m*n;
        while (l<r){
            int m = ( r + 1 + l ) /2;
            if (bfs(m))
                l=m;
            else
                r=m-1;
        }

        return l!=-1 ? (l==m*n ? 1e9:l) : l;
    }
    
};