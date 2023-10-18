class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> G[n+1] , cost(time), ind(n+1);
        for (auto i : relations){
            G[i[0]].push_back(i[1]);
            ind[i[1]]++;
        }
        vector<int> q;
        for (int i=1; i<=n; i++){
            if (ind[i]==0){
                q.push_back(i);
            }
        }
   
        while (!q.empty()){
            vector<int> t;
            for (auto  u : q){
                for (auto v : G[u]){
                    if (--ind[v]==0) 
                        t.push_back(v);
                    cost[v-1] = max(cost[v-1], cost[u-1] + time[v-1]);
                    
                }
            }
            q.swap(t);
        }
        return *max_element(begin(cost),end(cost));
    }
};