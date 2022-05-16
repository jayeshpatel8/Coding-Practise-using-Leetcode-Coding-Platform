class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        //vector<vector<int>> vis(m,vector<int>(n));
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        queue<array<int,2>> q;
        int row[8]={0,-1,1,0, 1,-1,-1, 1};
        int col[8]={-1,0,0,1, 1, 1,-1,-1};        
        q.push({0,0});
        int len=0;
        while(!q.empty()){
            len++;
            int sz = q.size();
            while (sz-- > 0){
                auto i = q.front(); q.pop();
                int i1=i[0],j1=i[1];
                
                if (i1==n-1 && j1==n-1)return len;
                for (int k=0; k<8; k++){
                    auto i2 = i1+row[k], j2 = j1+col[k];
                    if (i2<0 || j2<0 || i2 >= n || j2 >= n || grid[i2][j2] )
                        continue;
                    grid[i2][j2]=1;
                    q.push({i2,j2});
                }
            }            
        }
        return -1;        
    }
};