class Solution {
public:

    bool possibleToStamp(vector<vector<int>>& g, int h, int w) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> psum1(m+1, vector<int>(n+1)),stamp(m, vector<int>(n)),psum2(m+1, vector<int>(n+1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                psum1[i+1][j+1] = g[i][j] + psum1[i+1][j] + psum1[i][j+1] - psum1[i][j];


        for (int i = h - 1; i < m; ++i)
            for (int j = w - 1, i1 = i - h +1; j < n; ++j){
                int j1 = j-w+1;
                stamp[i][j] = (psum1[i+1][j+1] - psum1[i+1][j1] - psum1[i1][j+1] + psum1[i1][j1]) == 0;
            }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++){
                psum2[i+1][j+1] = stamp[i][j] + psum2[i+1][j] + psum2[i][j+1] - psum2[i][j];
            }

        for (int i = 0; i < m; i++)
            for (int j = 0, i1 = min(i + h - 1,m-1); j < n; j++){
                int  j1 = min(j+w-1,n-1);
                if (g[i][j] == 0 && (psum2[i1+1][j1+1] - psum2[i1+1][j] - psum2[i][j1+1] + psum2[i][j])==0)
                    return false;
            }

        return true;
    }
};