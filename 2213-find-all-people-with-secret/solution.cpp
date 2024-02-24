class Solution {
public:
    using pi = pair<int,int>;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pi>> g(n);
        for (auto &m : meetings){
            g[m[0]].push_back({m[2],m[1]});
            g[m[1]].push_back({m[2],m[0]});
        } 
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,0});
        pq.push({0,firstPerson});

        vector<bool> visited(n);
        
        while (!pq.empty()){
            auto [time, u] = pq.top(); pq.pop();
            if (visited[u]) continue;
            visited[u]=true; 
            for (auto [t, v] : g[u]){
                
                if (!visited[v] && t >= time){
                    pq.push({t,v});
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                ans.push_back(i);
            }
        }        
        return ans;
    }
};
