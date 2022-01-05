class Solution {
public:
    int best=INT_MAX;
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> g(n);
        vector<int> indegree(n);
        for (auto & e : edges){
            g[e[0]].push_back(e[1]),g[e[1]].push_back(e[0]);
            indegree[e[0]]++,indegree[e[1]]++;
        }
        queue<int> q;
        for (int i=0; i<n; i++)
            if (indegree[i] == 1) 
                q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int sz = q.size();
            ans.clear();
            while(sz-- > 0){
                int u = q.front(); q.pop();
                ans.push_back(u);
                for (auto &v : g[u]){
                    if (--indegree[v] == 1) 
                        q.push(v);
                }
            }
        }
        
        return ans;
    }

};