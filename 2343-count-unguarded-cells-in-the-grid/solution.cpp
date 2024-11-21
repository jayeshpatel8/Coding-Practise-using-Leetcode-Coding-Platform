class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> u(m,vector<int>(n)),d(u),l(u),r1(u),g(u);
        
        for (auto &i :  walls){
            g[i[0]][i[1]] = -1;
        }
        for (auto &i : guards){
            int r = i[0] ,c = i[1];
            g[r][c]=2;
        }
        for (int r=0; r<m; r++){
            int    v = 0;
            for (int c=0; c<n;c++){
                 if (g[r][c]== 2) v=1;
                else if (g[r][c]== -1) v= 0;
                
                l[r][c]=v;
            }
        }
        for (int r=0; r<m; r++){
            int    v = 0;
            for (int c=n-1; c>=0;c--){
                 if (g[r][c]== 2) v=1;
                else if (g[r][c]== -1) v= 0;
                
                r1[r][c]=v;
            }
        }
        for (int c=0; c<n;c++){
            int    v = 0;
            for (int r=0; r<m; r++){
                 if (g[r][c]== 2) v=1;
                else if (g[r][c]== -1) v= 0;
                
                u[r][c]=v;
            }
        } 
        for (int c=0; c<n;c++){
            int    v = 0;
            for (int r=m-1; r>=0; r--){
                 if (g[r][c]== 2) v=1;
                else if (g[r][c]== -1) v= 0;
                
                d[r][c]=v;
            }
        }         
        int ans= 0;
        for (int r=0; r<m; r++){
            for (int c=0; c<n;c++){
                if (g[r][c]==0){
                    if (l[r][c]  || r1[r][c] || u[r][c] || d[r][c])
                        continue;
                    ans++;
                }
            }
        }
                   
        return ans;
    }
};
