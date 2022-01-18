class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<int> dp(M + N);
        map<int, vector<array<int,2>>> p;
        for (int i=0; i<M; i++){
            for (int j=0;j<N; j++){
                p[matrix[i][j]].push_back( {i,j});
            }
        }
        vector<int> rank(M+N);
        for (auto & [k,v] : p){
            vector<int> uf(M+N,-1);
            for(auto &e:v){
                int u1 = find(uf,e[0]), v1 = find(uf,M+e[1]);
                if (u1!= v1)
                {
                    uf[u1] = v1;
                    rank[v1] = max(rank[v1],rank[u1]);
                }
            }
            auto rank2=rank;
            for(auto &e:v){
                int u1 = find(uf,e[0]);
                    rank2[e[0]]=rank2[M+e[1]] = matrix[e[0]][e[1]] = 1 + rank[u1];
            }            
            swap(rank2, rank);           
        }
        return matrix;
    }
    int find( vector<int>& uf, int i){
        return uf[i]==-1? i : uf[i] = find (uf, uf[i]);
    }
};