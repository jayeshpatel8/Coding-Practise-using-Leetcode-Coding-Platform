class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        vector<vector<int>> row(m+2, vector<int>(n+2)),col(row),dl(row),dr(row);
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                row[i][j] = row[i][j-1]+ grid[i-1][j-1];
                col[i][j] = col[i-1][j]+ grid[i-1][j-1];
                dl[i][j] = dl[i-1][j-1]+ grid[i-1][j-1];
                dr[i][j] = dr[i-1][j+1]+ grid[i-1][j-1];
            }
        }
        int res=0;
        for (int k = min(m,n); k>=0; k--)
        {
            for (int i=1; i<=m-k; ++i){
                for (int j=1; j<=n-k; ++j){
                    {
                        
                        
                        int sum = dl[i+k][j+k]-dl[i-1][j-1] ;
                        
                        bool match = sum == (dr[i+k][j] - dr[i-1][j+k+1]);
                        
                        for (int n=0; n<=k && match; n++){
                            match &= sum == (row[i+n][j+k] - row[i+n][j-1]);
                            match &= sum == (col[i+k][j+n] - col[i-1][j+n]);
                        }
                        //res = (match)? k: res;
                        if (match) return k +1;
                    }
                }
            }
        }
    return 0;
    }
};