class Solution {
public:
    vector<int> uf,size;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n);
        for (int i=0; i<n; i++){
            if (colour[i]==0 && !assign(graph, i, 1, colour))
                return false;
        }
        return true;
    }
    bool assign(vector<vector<int>>& graph, int i , int c ,vector<int>& colour) {
        if (colour[i] != 0 ) return colour[i] == c;
        colour[i] = c;
        for (auto j : graph[i]){
            if (colour[j]==0 && !assign(graph, j , -c,colour))
                return false;
            else if (colour[j] != -c)
                return false;                
        }
        return true;
    }
    bool isBipartite2(vector<vector<int>>& graph) {
        int n = graph.size();
        uf.resize(n+2,-1);
        size.resize(n+2);
        for (int i=0; i<n; i++){
            auto pi = find(i);
            for (auto j : graph[i]){
                if (pi == find(j)) return false;
                join(graph[i][0],j);
            }
        }

        return true;
    }
    int find(int i){
        return uf[i]<0?i : (uf[i] = find(uf[i]));
    }
    void join(int i, int j){
        auto pi = find(i), pj = find(j);
        if (pi != pj){
            if (size[pi] <= size[pj]){
                size[pi] += size[pj], uf[pj]=pi;
            }
            else
                size[pj] += size[pi], uf[pi]=pj;
        }
    }
};