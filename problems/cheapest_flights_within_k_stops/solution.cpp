class Solution {
public:

    

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, -1);
        vector<vector<pair<int,int>>> graph(n);
        for ( auto &f : flights){
            graph[f[0]].push_back({f[1],f[2]});
        }
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>   q;
        q.push({0,k,src}); // cost, step, node
        while(!q.empty()){
            auto v = q.top(); q.pop();

            if(v[2]==dst ) return v[0];

            if(v[1]<0 || dis[v[2]] >=  v[1]) continue;
            dis[v[2]] =  v[1];
            for (auto &e : graph[v[2]])
                //if ( e.first==dst)
                    q.push({e.second+v[0],v[1]-1,e.first});
        }
        return -1;
    }
};