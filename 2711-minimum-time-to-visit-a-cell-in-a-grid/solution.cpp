class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (min(grid[0][1], grid[1][0]) > 1)
            return -1;
        
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> vis(M, vector<int>(N, INT_MAX));
        priority_queue<array<int,3>,vector<array<int,3>>, greater<>> q;
        q.push({0,0,0});
        int dirs[] = {-1,0,1,0,-1} ;
        while (!q.empty()){
            auto [next, r,c] = q.top(); q.pop();
            
            for (int d=0; d<4; d++){
                auto r1 = r +dirs[d], c1 = c + dirs[d+1];
                if (r1<0 || c1<0 || r1 >= M || c1 >= N ) continue;
                int t = next + 1;
                if (t < grid[r1][c1]) t = grid[r1][c1] + (grid[r1][c1] - t ) % 2;
                if (r1==M-1 && c1==N-1) return t;
                if ( t< vis[r1][c1]){
                    vis[r1][c1]=t;
                    q.push({t,r1,c1});
                }
            }
        }
        return -1;
    }
};
