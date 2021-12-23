class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prq) {
        vector<int> deg(n);
        vector<int> graph[n];
        
        for ( auto &i : prq){
            graph[i[1]].push_back(i[0]);
            deg[i[0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for (int i=0; i<n;i++){
            if (deg[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int i = q.size();
            while (i-- > 0){
                int u = q.front(); q.pop();
                for (auto v : graph[u]){
                    if (--deg[v]== 0 )
                        q.push(v);
                }
                ans.push_back(u);
            }
        }
        if (ans.size() == n) return ans;
        return {};
    }
};