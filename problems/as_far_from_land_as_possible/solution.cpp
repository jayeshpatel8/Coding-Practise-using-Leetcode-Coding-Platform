class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        int vis[101][101]={};
        queue<array<int, 2>> q;
        for (int i =0; i<N; i++)
        for (int j =0; j<N; j++){
            if (grid[i][j] == 1) q.push({i,j});
        }
      
        int ans = -1;
        int dirs[5]= {1,0,-1,0,1};
        while (!q.empty()){
            int sz = q.size();
            while (sz--> 0){
                auto cur = q.front(); q.pop();
                for (int d=0; d<4; d++){
                    int r= cur[0] + dirs[d];
                    int c= cur[1] + dirs[d+1];
                    if (r<0||c<0||r>=N||c>=N || grid[r][c]==1 || vis[r][c] ) continue;
                    vis[r][c]  =  1;
                    q.push({r,c});                    
                }
            }
            ans++;
        }
        return ans <=0 ? -1 : ans;
    }
};