class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
     vector<vector<int>> M(n+1,vector<int>(n+1,0));
        vector<int> indegree(n+1,0);
        for (auto i: edges){
            int u =i[0], v = i[1];
            M[u][v]=1;
            M[v][u]=1;
            indegree[u]++;
            indegree[v]++;
        }
        int res=INT_MAX;
        for (int u=1; u<=n; u++){
            {
                if (indegree[u]>=2){                    
                    for (int v=u+1; v<=n; v++){
                        if (M[u][v] && indegree[v]>=2){
                            for (int w=v+1; w<=n; w++){
                                if (M[u][w] &&(M[w][v])){
                                    res = min(res, indegree[u]+indegree[v]+indegree[w]-6);
                                    if (res==0) return 0;                                
                                }
                            }
                        }
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};