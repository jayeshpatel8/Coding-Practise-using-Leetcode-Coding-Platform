class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> G(n);
        vector<int> ind(n);
        for (auto &e :edges)
            G[e[0]-1].insert(e[1]-1),G[e[1]-1].insert(e[0]-1),ind[e[0]-1]++,ind[e[1]-1]++;
        vector<int> odd;
        for (int i=0;i<n; i++)
            if (ind[i] & 1) odd.push_back(i);
        int n1 = odd.size();
        if (n1 >4 || n1 & 1) return false;
        if (n1==2){
            int u=odd[0], v=odd[1];
           
            if (G[u].count(v)==0) return true;
           
            for (int i=0; i<n; i++){
                if (i==u || i==v || G[u].count(i)|| G[v].count(i)) continue;
                return true;
            }
           
            return false;
        }
        
        
        function<bool(int,int)> dfs = [&](int i, int mask)->bool{
            if (i>=n1) return mask == 0;

            for (int j=0; j<n1; j++){
                if (i==j || ((1<<j) & mask)==0 || G[odd[i]].count(odd[j])) continue;
                if (dfs(i+1,mask & ~(1<<j)))
                    return true;
            }
            return false;
        };
        return dfs(0,(1<<n1)-1);
    }
};