class Solution {
public:
    vector<int> uf;
    vector<int> rank ,crit,pcrit;
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)     {
        for (int i = 0; i < edges.size(); ++i)         edges[i].push_back(i);
        sort(begin(edges),end(edges),[](auto  &a, auto &b){return a[2] < b[2];});
        
        int mcost = getmstcost(edges,-1,n);

        for (int i=0; i<edges.size(); i++){
            if (getmstcost(edges,i,n) > mcost){
                crit.push_back(edges[i][3]);                
            }
            else if (getmstcost(edges,-1,n,i) == mcost)
                pcrit.push_back(edges[i][3]);
        }
        return {crit,pcrit};
    }
    int find(int i){return uf[i] < 0 ? i : uf[i]=find(uf[i]);}
    void connect(int i, int j){
        int pi = find(i), pj = find (j);
        if (pi==pj) return;
        if (rank[pi] < rank[pj])
            uf[pi]=pj,rank[pj] += rank[pi];
        else
            uf[pj] = pi,rank[pi] += rank[pj];
         //if (rank[pi] == rank[pj])
             //rank[pi]++;
    }
        int getmstcost( vector<vector<int>>& edges, int block, int n, int  pre_edge=-1){
            uf = vector<int> (n,-1); 
            rank = vector<int> (n,1);
            int cost  = 0,v=n-1;;
            if (pre_edge != -1)
                connect(find(edges[pre_edge][0]),find(edges[pre_edge][1])),--v,cost=edges[pre_edge][2];
            for (int i=0; v && i<edges.size(); i++){
                if (i == block) continue;
                auto e = edges[i];
                if (find(e[0]) == find(e[1])) continue;
                connect(find(e[0]),find(e[1]));
                    v--;
                cost += (e[2]);
            }
            return v ? 1e9 : cost;
        }
};