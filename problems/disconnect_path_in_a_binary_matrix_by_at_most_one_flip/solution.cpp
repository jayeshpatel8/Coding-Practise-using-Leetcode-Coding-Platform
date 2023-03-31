class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        function<bool(int,int)> dfs = [&](int r, int c){
            if (r>=M || c >=N ) return false;
            if (r==M-1 && c==N-1) return true;
            if (grid[r][c]==0) return false;
            grid[r][c]=0;

            return dfs(r+1,c) ||dfs(r,c+1);
        };
        if (!dfs(0,0)) return true; 
        grid[0][0]=1;
        if (dfs(0,0)) return false;
        
        return true;
    }
};