class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), m_cost=M+N-1;
        vector<vector<int>> vis(M,vector<int>(N,INT_MAX));
        priority_queue<array<int,3>,vector<array<int,3>>, greater<array<int,3>>> pq;
        pq.push({0,0,0});
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto a = pq.top(); pq.pop();
            if (a[1]==M-1 && a[2]==N-1) return a[0];
            for (int d=0; d<4; d++){
                int i = a[1]+dirs[d][0], j = a[2]+dirs[d][1];
                if (i<0 || i >=M || j <  0 || j >=N ) continue;
                int cost = a[0] + (grid[a[1]][a[2]] != d+1);
                if (cost  < vis[i][j] && cost <= m_cost ){
                    vis[i][j]=cost;
                    pq.push({cost,i,j});
                }
            }
        }
        return M*N-2;
    }
};
