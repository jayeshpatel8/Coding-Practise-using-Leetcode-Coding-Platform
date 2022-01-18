class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size(), first, edge2=-1, cycle = -1;
        vector<int> parent(n+1,-1), uf(n+1);
        
        for (int i=0; i< n; i++){
            int u =  edges[i][0] , v  = edges[i][1];
            if (parent[v] != -1){
                first = parent[v];;
                edge2 = i;       continue;                   
            }
            parent[v]=i;
            int p1 = find(uf,u), p2=find(uf,v);
            if (p1 ==  p2){
                cycle=i;
            }
            else
                uf[p2]=p1;
        }

        if (cycle == -1){
          //  int u = edges[cycle][0], v = edges[i][1];
            return edges[edge2];
        }
        if (edge2 == -1)
        {
            return edges[cycle];
        }   
        return edges[first];
        
    }
    int find(vector<int> &uf, int i){
        return uf[i] ==0 ? i: uf[i] = find (uf, uf[i]);
    }
};