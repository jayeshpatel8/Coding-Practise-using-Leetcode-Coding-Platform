class Solution {
public:

    vector<int> constructDistancedSequence(int n) {
        vector<int> res (n*2 - 1) ;
        vector<bool> vis(n+1);
        dfs(n,res,vis,0);
        return res;
    }
    bool dfs(int n, vector<int>& res, vector<bool>&vis, int i){
        if (i >=res.size()) return true;
        if (res[i]) return dfs(n,res,vis,i+1);

        for (int j=n; j>0; j--){
            if (vis[j]) continue;
            if (j!=1 && (i+j >=n*2-1 || res[i+j])) continue;

            vis[j]=true;
            res[i]=j;
            if (j != 1) res[i+j]=j;
            if (dfs(n,res,vis, i+1)) return true;
            vis[j] = false;res[i]=0;
            if (j != 1) res[i+j]=0;
        }
        return false;
    }
};
