class Solution {
public:
    int waysToBuildRooms(vector<int>& pRoom) {
        int n = pRoom.size(), mod =  1e9 + 7;
        vector<vector<int>> g(n,vector<int>());
        vector<int> dp(n);
        long long fact = n;
        for (int i=1; i<n; i++){
            g[pRoom[i]].push_back(i);
            fact = (fact * i)%mod;
        }
        long cnt=1;
        dfs(g,dp,0);
        for (int i=0; i<n; i++)
            cnt  =  (cnt * dp[i])%mod;
        return (fact *  mod_inv(cnt,mod-2,mod))%mod;
    }
    int dfs(vector<vector<int>>& g, vector<int>& dp,int u){
        int size = 1;
        for (auto v : g[u])
            size += dfs(g,dp,v);
        return dp[u]=size;
    }
    int mod_inv(int x, unsigned int y, int m){
        if (y==1) return x;
        long s = mod_inv(x,y/2,m) ;
        long ans = (s * s)%m;
        if (y%2)
            ans  = (ans * x) %m;
        return ans;        
    }
};