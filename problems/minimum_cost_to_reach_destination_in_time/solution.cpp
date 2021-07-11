class Solution {
public:

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        int  N=fee.size();
        int mcost = INT_MAX;
        vector<vector<array<int,3>>> graph(N);
        
        for (auto e : edges){
            int u = e[0], v =e[1];
            if (v!= N-1) graph[u].push_back({e[2],fee[v],v});
            if (u!= N-1) graph[v].push_back({e[2],fee[u],u});
        }
         
        vector<int> ccost(N,INT_MAX),ctime(ccost);        
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        pq.push({0,fee[N-1],N-1});
        while (!pq.empty()){
           
            auto [t,c,u] = pq.top();pq.pop();
            
            for ( auto &[t1,c1,v] : graph[u]){
                int time =  t+ t1, cost = c + c1;
                if (time <= maxTime && cost<mcost ){
                    if (v == 0) mcost = cost;
                    else if (ccost[v]>cost || ctime[v]>time){
                        ccost[v] =cost;ctime[v]=time;
                        pq.push({time,cost,v});
                    }
                }
            } 
        }
        return mcost==INT_MAX ? -1 : mcost;
        
    }
};

