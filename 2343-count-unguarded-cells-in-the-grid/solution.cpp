class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> merged(m,vector<int>(n));
        for (auto &i : walls)
            merged[i[0]][i[1]] = 2;
        for (auto &i : guards)
            merged[i[0]][i[1]] = 1;

        for ( auto i=0; i<m; i++){
            int g=0,g_rev=0;
            for (int j=0; j<n; j++){
                auto c= merged[i][j];
                if (c ==2) g=0;
                if (c == 1) g=1;
                if (g && merged[i][j] != 1) 
                    merged[i][j]=3;
                c= merged[i][n-1-j];
                if (c ==2) g_rev=0;
                if (c == 1) g_rev=1;
                if (g_rev && merged[i][n-1-j] != 1) 
                    merged[i][n-1-j]=3;
            }
        }
 
        for (int j=0; j<n; j++){
            int g=0,g_rev=0;
            for (int i=0; i<m; i++){
                auto c= merged[i][j];
                if (c ==2) g=0;
                if (c == 1) g=1;
                if (g && merged[i][j] != 1) 
                    merged[i][j]=3;
                c= merged[m-1-i][j];
                if (c ==2) g_rev=0;
                if (c == 1) g_rev=1;
                if (g_rev && merged[m-1-i][j] != 1) 
                    merged[m-1-i][j]=3;
            }
        }
        int ans=0;
        for (auto &i : merged)
            for (auto &j  : i)
                if (j == 0) ans++;
        return ans;
    }
};
