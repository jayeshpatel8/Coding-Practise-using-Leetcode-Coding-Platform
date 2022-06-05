class Solution {
public:
    bool vis[9][9]={};
    bool col[9]={};
    int ans = 0, N ;
    int totalNQueens(int n) {
        N = n;
        dfs(0);
        return ans;
    }
    void dfs(int r){
        if (r >= N) ans++;
        else{
            for (int c =0; c <N; c++){
                if (!col[c] && isallow(r,c)){
                    vis[r][c]=col[c]=true;
                    dfs(r+1);
                    vis[r][c]=col[c]=false;
                }
            }
        }
    }
    bool isallow(int r , int c){
        for (int r1=r-1, c1=c-1; r1>=0 && c1 >=0; r1--,c1--)
            if (vis[r1][c1]) return false;
        for (int r1=r-1, c1=c+1; r1>=0 && c1 <N; r1--,c1++)
            if (vis[r1][c1]) return false;
        return true;
    }
};