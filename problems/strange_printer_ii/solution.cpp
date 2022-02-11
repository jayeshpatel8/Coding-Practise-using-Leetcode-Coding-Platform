class Solution {
public:
    bool isPrintable(vector<vector<int>>& grid) {
        vector<array<int,4>> rect (61,{INT_MAX,INT_MAX,INT_MIN,INT_MIN});
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int c = grid[i][j];
                rect[c][0] = min(rect[c][0], i);
                rect[c][1] = min(rect[c][1], j);
                rect[c][2] = max(rect[c][2], i);
                rect[c][3] = max(rect[c][3], j);
            }            
        }
        vector<unordered_set<int>> col(61);
        for (int c=0;c<61; c++)
            for (int i=rect[c][0]; i<=rect[c][2]; i++)
                for (int j=rect[c][1]; j<=rect[c][3]; j++)
                    if (grid[i][j] != c)
                        col[c].insert(grid[i][j]);
        
        for (int c=0;c<61; c++){
            if (!dfs(col,c,vector<int>(61) = {})){
                return false;
            }
        }
        return true;   
    }
    bool dfs(vector<unordered_set<int>> & col,int c,vector<int> & vis ){
        if (vis[c]!=0) 
            return vis[c]==2;
         vis[c]=1;
        for (auto j : col[c]){
            if (!dfs(col,j,vis)) {
                return false;
            }
        }
         vis[c]=2;
        return true;
    }
};
