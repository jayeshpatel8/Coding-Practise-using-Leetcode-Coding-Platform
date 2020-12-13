class Solution {
public:
    int cache[50][50][50];
    int N ;
    int cherryPickup(vector<vector<int>>& grid) {
        
        N = grid.size();
        memset(cache, -1, sizeof(cache));
        
        return max(0,collect(grid, 0,0,0));        
    }
    int collect(vector<vector<int>>& g, int i, int j, int l){
        int k = i + j - l;
        
        if (i>=N || j >=N || k >=N || l>=N|| g[i][j] == -1 || g[k][l] == -1) return INT_MIN;
        
        if (i==N-1 && j==N-1) return g[i][j];
        
        if (cache[i][j][l] != -1 ) return cache[i][j][l];
        
        int res = g[i][j];
        if (i!=k && j!=l) res += g[k][l];
        
        res += max({collect(g,i,j+1,l),
                    collect(g,i,j+1,l+1),
                    collect(g,i+1,j,l),
                    collect(g,i+1,j,l+1)});
        
        return cache[i][j][l] = res;
    }
#if 0    
    int cherryPickup(vector<vector<int>>& grid, int r1, int c1, int c2) {
        int r2 = r1 + c1 -c2;
        
        if (r1>=N || r2>=N || c1>=N || c2>=N || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        return INT_MIN;
        
        if (r1==N-1 && c1==N-1) return cache[r1][c1][c2]= grid[r1][c1];
        if (cache[r1][c1][c2] !=-1 ) return cache[r1][c1][c2];
        
       
        
        int res = max ({cherryPickup(grid, r1+1,c1,c2), cherryPickup(grid, r1,c1+1,c2),
                    cherryPickup(grid, r1,c1+1,c2+1), cherryPickup(grid, r1+1,c1,c2+1)});

        res+=grid[r1][c1];
        if (r1 != r2 && c1!=c2) res +=grid[r2][c2];

        return cache[r1][c1][c2]= res;        
    }
#endif    
};
