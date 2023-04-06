class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int M =    grid.size(), N = grid[0].size();

        int dirs[] = {-1,0,1,0,-1};

        function<int(int,int)> dfs = [&](int i, int j)->int{
            if ( i<0 || j<0 || i>=M || j>= N) return false;
            if (grid[i][j])
                return true;

            grid[i][j]=1;
            bool ans=true;
            for (int d= 0; d<4; d++){
                int i1=i+dirs[d], j1 = j + dirs[d+1];
                ans &= dfs(i1,j1);
            }
            return ans;
        };
        int ans = 0;
        for (int i=0; i<M-1; i++){
            for (int j=0; j<N-1; j++){
                if (grid[i][j] == 0 ){
                    ans += dfs(i,j);
                    
                }
            }
        }
        return ans;
    }
};