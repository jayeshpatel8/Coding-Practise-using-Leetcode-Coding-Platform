class Solution {
public:
    int uf[10001]={}, cnt= 0 ,M,N;
    int dir[5] = {-1,0,1,0,-1};
    int closedIsland(vector<vector<int>>& grid) {
         M = grid.size(), N = grid[0].size();
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (i==0 || j ==0 || i==M-1 || j ==N-1 ){
                    if (grid[i][j]== 0)
                        dfs(grid,i,j);
                }
            }
        }
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
                cnt+= (grid[i][j]== 0);
        
        for (int i=1; i<M-1; i++){
            for (int j=1; j<N-1; j++){        
                if (grid[i][j]== 0){
                    for (int d  = 0; d<4; d++){
                        int x = i + dir[d], y = j + dir[d+1];
                        if (grid[x][y] == 0)
                            connect(M*i+j,M*x+y);
                    }
                }
            }
        }
        return cnt;
    }
    int find(int i){
        return uf[i] == 0 ? i : uf[i] = find (uf[i]);
    }
    void connect (int i, int j){
        int p1 = find(i), p2 = find (j);
        if (p1 != p2){
            uf[p1] = p2;
            cnt--;
        }
    }
    void dfs(vector<vector<int>>& grid , int i, int j){
        if (i<0 || j <0 || i>= M || j >= N ||grid[i][j] ) return;
        grid[i][j] = 1;
        for (int d  = 0; d<4; d++){
            int x = i + dir[d], y = j + dir[d+1];
                dfs(grid,x,y);
        }
    }
};