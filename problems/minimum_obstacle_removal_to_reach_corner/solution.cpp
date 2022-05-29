class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int  M =grid.size(), N = grid[0].size();
        vector<vector<int>> dist(M+1,vector<int>(N+1, N+M-3));
        
        queue<array<int,2>> q;
        q.push({0,0});
        dist[0][0]=0;
        int dirs1[]={-1,0,1,0,-1};
    
        int ans = M+N-3;
        while (!q.empty()){
            auto [r,c] = q.front(); q.pop();
            for (int i=0; i<4; i++){
                int r1 = r +  dirs1[i] , c1 =c + dirs1[i+1]  , d= dist[r][c];

                if (r1 <0 || c1 <0 || r1 >=M || c1 >=N || dist[r1][c1] <= d + grid[r1][c1]) continue;
                dist[r1][c1] =  d + grid[r1][c1];
                q.push({ r1, c1 });
            }
        }

        return dist[M-1][N-1];
    }    
    int minimumObstacles1(vector<vector<int>>& grid) {
        int  M =grid.size(), N = grid[0].size();
        vector<vector<int>> dist(M+1,vector<int>(N+1, N+M-3));
        
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>> pq;
        pq.push({0,0,0});
        dist[0][0]=0;
        int dirs1[]={-1,0,1,0,-1};
    
        int ans = M+N-3;
        while (!pq.empty()){
            auto [d,r,c] = pq.top(); 

            pq.pop();
            if (r==M-1 && c==N-1) return d;
            if (dist[r][c] < d) continue;

            for (int i=0; i<4; i++){
                int r1 = r +  dirs1[i] , c1 =c + dirs1[i+1];

                if (r1 <0 || c1 <0 || r1 >=M || c1 >=N || dist[r1][c1] <= d + grid[r1][c1]) continue;
                dist[r1][c1] =  d + grid[r1][c1];
                pq.push({  dist[r1][c1] , r1, c1});
            }
        }

        return ans;
    }
};