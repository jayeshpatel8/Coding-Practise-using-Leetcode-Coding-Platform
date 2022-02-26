class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<vector<bool>> seen(N,vector<bool>(1<<N));
        queue<array<int,2>> q;
        int step = 0, endMask =  (1<<N)-1;
        for (int i=0; i<N; i++){
            q.push({i,1<<i});
            seen[i][1<<i]=true;
        }
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto u  = q.front(); q.pop();
                for (auto v : graph[u[0]]){
                    int mask = u[1] | (1<<v);
                    if (mask == endMask) return step +1 ;
                    if (!seen[v][mask]){
                        seen[v][mask]=true;
                        q.push({v,mask});
                    }
                }
            }
            step++;
        }
        return 0;
    }
};