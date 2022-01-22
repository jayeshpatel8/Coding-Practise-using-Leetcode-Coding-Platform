class Solution {
public:
    
    int  M, N;
    int dirs[5] = {-1,0,1,0,-1};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pr, vector<int>& start, int k) {
        M  = grid.size(), N = grid[0].size();
        queue<array<int,2>> q;
        vector<vector<int>> ans;
        q.push({start[0], start[1]});
        vector<vector<bool>> vis(M,vector<bool>(N));
        vis[start[0]][start[1]] = 1;
        int step=1, asz=0;
         
        while (!q.empty() && asz < k){
            int sz = q.size(),rsz= 0;
            vector<array<int,3>> rank;
            while (sz-- > 0){
                auto & a = q.front();
                int i = a[0], j = a[1], p = grid[i][j];
                
                if (p >= pr[0] && p<= pr[1]){                    
                    rank.push_back({p,i,j});   rsz++;
                }
                for (int d=0; d<4; d++){
                    int i1= i+dirs[d], j1 = j+dirs[d+1];
                    if (i1<0 || i1>=M || j1 <0 || j1>=N || grid[i1][j1] == 0  || vis[i1][j1]) continue; 
                    vis[i1][j1]=1;
                    q.push({i1,j1});                    
                }
                 q.pop();    
            }
            int i=0;
            sort(begin(rank), end(rank));
            while (i < rsz && ans.size() < k) {
                ans.push_back({rank[i][1],rank[i++][2]});;    
            }
            step++;
        }       
        return ans;
    }
};