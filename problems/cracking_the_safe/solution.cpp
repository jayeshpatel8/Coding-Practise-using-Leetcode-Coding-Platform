class Solution {
public:
    vector<vector<bool>> vis;
    int N,K,kn;
    string s;
    string crackSafe(int n, int k) {
        
        if (k==1) return string(n,'0');
        kn=1;
        N= n, K= k;
        for (int i=0; i<n-1; i++) kn *=k;
        vis.resize(kn,vector<bool>(k));
        dfs(0);
        return s + s.substr(0,n-1);
    }
    void dfs(int u){
        for (int i=0; i<K; i++){
            if (vis[u][i]==0){
                vis[u][i]=1;
                dfs((u*K + i)%kn);
                s.push_back('0'+i);
            }
        }
    }
};
