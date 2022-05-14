class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dp(n,INT_MAX);
        vector<array<int,2>> edge[n];
        for (auto &t : times){
            edge[t[0]-1].push_back({t[1]-1,t[2]});
        }
        priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>> pq;
        pq.push({0,k-1});
        
        while (!pq.empty()){
            auto [w,u] = pq.top(); pq.pop();
            //--u,--v;
            if (dp[u] <= w) continue;
            
            dp[u] = w;
            for (auto &v : edge[u]){
               // if (w+v[1] < dp[v[0]])
                    pq.push({w+v[1],v[0]});
            }
        }
        auto ans = *max_element(begin(dp),end(dp));
        return ans == INT_MAX ? -1 : ans;
    }
};