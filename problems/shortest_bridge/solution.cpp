class Solution {
public:
int dirs[5] = {-1,0,1,0,-1} , N;
    int shortestBridge(vector<vector<int>>& grid) {
        N = grid.size();
        function<void(int,int)> dfs = [&](int i,int j)->void{
            if (i<0 || i >=N || j<0 || j>=N || grid[i][j]!=1) return;
            grid[i][j] = 2;
            for ( int d = 0;  d<4; d++){
                int i1 = i + dirs[d], j1 =  j + dirs[d+1];
                dfs(i1,j1);
            }     
        };
        for (int i = 0; i<N; i++){
            bool f=0;
            for (int j = 0; j<N; j++)
                if (grid[i][j]) {
                    dfs(i,j);
                    f=1;
                    break;
                }
            if (f) break; 
        }
        int cnt=2; 
        while (cnt <=1001){
            for (int i = 0; i<N; i++){
                for (int j = 0; j<N; j++){
                    if (grid[i][j]==cnt){
                        for ( int d = 0;  d<4; d++){
                            int i1 = i + dirs[d], j1 =  j + dirs[d+1];
                            if (i1<0 || i1 >=N || j1<0 || j1>=N || grid[i1][j1]==cnt) continue;
                            if (grid[i1][j1]==1) return cnt-2;
                            grid[i1][j1]=cnt+1;
                        }           
                    }
                }
            }
            cnt++;
        }
        return -1;
    }  
};