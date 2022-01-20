
class Solution {
public:
    int M, N, cnt=0, ans = 900;
    bool vis[30][30] = {};
    vector<array<int,2>> island;
    int minDays(vector<vector<int>>& grid) {
        M = grid.size(), N = grid[0].size();       
        for ( int i =0; i<M; i++){
            for ( int j =0; j<N; j++){
                if (grid[i][j] == 1 && vis[i][j] == 0){
                    if (cnt ) return 0;
                    dfs(grid, i, j);
                }
            }
        }
   
        if (cnt <=2) return cnt;

        for (auto & [i,j] : island){
            grid[i][j]=0;
            for ( int d =0; d<4; d++){
                int i1 = i + dirs[d], j1 = j + dirs[d+1];                
                if (i1<0 || i1>=M || j1<0 || j1>= N || grid[i1][j1]==0) continue;
                memset(vis,0,sizeof(vis));

                if (dfs2(grid,i1,j1) < cnt -1 ) return 1;
                break;
            }            
            grid[i][j]=1;
        }
        return 2;
    }
    int dirs[5] = {-1,0,1,0,-1};
    void dfs (vector<vector<int>>& grid, int i , int j){
        if (i<0 || i>=M || j<0 || j>= N || vis[i][j] || grid[i][j]==0) return;
        vis[i][j] =1;
        island.push_back({i,j});
        cnt++;
        for ( int d =0; d<4; d++){
            int i1 = i +dirs[d], j1 = j + dirs[d+1];
            dfs(grid,i1, j1);
        }
    }
    int dfs2 (vector<vector<int>>& grid, int i , int j){
        if (i<0 || i>=M || j<0 || j>= N || vis[i][j] || grid[i][j]==0) return 0;
        vis[i][j] = 1;
        int ans = 1;
        for ( int d =0; d<4; d++){
            int i1 = i +dirs[d], j1 = j + dirs[d+1];
            ans += dfs2(grid,i1, j1);
        }
        return ans;
    }    
};
    
