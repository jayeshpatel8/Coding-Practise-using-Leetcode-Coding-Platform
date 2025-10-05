class Solution {
public:
    int m , n , dirs[5] = {-1,0,1,0,-1};
    vector<vector<bool>> P,A;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& H) {
         m = H.size(), n = H[0].size();
        P.resize(m,vector<bool>(n));
        A.resize(m,vector<bool>(n));
        
        for (int i=0;i<m; i++)
        {
            if (!P[i][0])
                dfs(H,i,0,P);
            if (!A[i][n-1])
                dfs(H,i,n-1,A);
        }
        for (int i=0;i<n; i++)
        {
            if (!P[0][i])
                dfs(H,0,i,P);
            if (!A[m-1][i])
                dfs(H,m-1,i,A);
        }        
        vector<vector<int>> ans;
        for (int i=0;i<m; i++)
            for (int j =0; j<n; j++)
                if (P[i][j] && A[i][j])
                    ans.push_back({i,j});
        return ans;
    }
    void dfs(vector<vector<int>>& H, int i, int j, vector<vector<bool>>& vis){
        
        vis [i][j] = true;
        
        for (int d=0; d<4; d++){
            int i1 = i+dirs[d] , j1 = j + dirs[d+1];
            if (i1<0 || j1<0 || i1>=m || j1>=n || vis[i1][j1] || H[i][j] > H[i1][j1]) continue;
            dfs(H,i1, j1,vis);
        }
    }
};
