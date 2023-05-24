class Solution {
public:

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int N = nums.size();
        unordered_set<int> st(begin(nums),end(nums));
        vector<vector<int>> cop_n(51),G(N);
        for (auto i : st)
            for (auto i2 : st)
                if (__gcd(i,i2)==1) 
                    cop_n[i].push_back(i2);

        for (auto &e : edges) 
            G[e[0]].push_back(e[1]),G[e[1]].push_back(e[0]);
        vector<int> ans(N),vis(N);
        queue<pair<int,vector<int>>> q;
        q.push({0, vector<int>(51,-1)});
        vis[0]=1;
        while (!q.empty()){
           // int sz = q.size();
            
            //while(sz-- > 0)
            {
                auto &[u, cops] = q.front(); 
                auto  n = nums[u];
                ans[u] = cops[n];                
                for (auto co : cop_n[n])
                    cops[co]=u;                
                for (auto v : G[u]){
                    if (vis[v]) continue;                    
                    vis[v]=1;
                    q.push({v,cops});
                }
                q.pop();
            }
            
        }
        return ans;
    }
};