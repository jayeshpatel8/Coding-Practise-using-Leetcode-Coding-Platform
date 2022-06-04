class Solution {
public:
    int N ;
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> vis(n,string(n,'.'));
        vector<bool> col(n);
        N = n;
        dfs(vis,col,0);
        return ans;
    }
    void dfs(vector<string>& vis, vector<bool>& col, int r){
        if (r==N) {
            ans.push_back(vis);
            return;
        }
        
        for (int c=0; c<N; c++){
            if (!col[c] && isallowed(vis,r,c)){
               vis[r][c]='Q';
                col[c]=true;
                dfs(vis,col,r+1);
                col[c]=false;
                vis[r][c]='.';
            }
        }
        
    }
    bool isallowed(vector<string>& vis, int r,int c){
        for (int j1=c-1, r1 = r-1; r1>=0 && j1>=0; r1--,j1--){
            if (vis[r1][j1] == 'Q') return false;
        }
        for (int j1=c+1, r1 = r-1; r1>=0 && j1<N; r1--,j1++){
            if (vis[r1][j1] == 'Q') return false;
        }
        return true;
    }
};