class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int N = roads.size();
        vector<vector<int>> G(N+1);
        for ( auto &e : roads){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        long long fuel = 0;
        function<long long(int,int)> dfs = [&](int node, int u)->int{
            long long rep = 1;
            for (auto v : G[node]){
                if (v != u){
                    rep += dfs(v,node);
                }
            }
            if (node){
                fuel += rep/seats + ((rep%seats)!=0);
            }
            return rep;
        };
        dfs(0, -1);
        return fuel;
    }
};