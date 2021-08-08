class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        map<int,vector<pair<int,int>>> map;
        int M = matrix.size(), N = matrix[0].size();
        for (int i  = 0; i < M; i++){
            for (int j  = 0; j < N; j++){
                map[matrix[i][j]].push_back({i,j});
            }
        }
        vector<int> rank(M+N) ;
        
        for  (auto &[v, val] : map){
            vector<int> uf(M+N);
            iota(begin(uf), end(uf), 0 );
            for (auto idx : val){
                // connect all
                int r = idx.first, c = idx.second;
                int r1 = find(uf,r), c1= find(uf,M + c);
                uf[r1] = c1;
                rank[c1] = max(rank[r1],rank[c1]);
            }
            auto rank2 = rank;
            for (auto idx : val){
                int r = idx.first, c = idx.second;
                int r1 = find(uf,r);
                rank2[r] = rank2[M + c] = matrix[r][c] =rank[r1]+1;           
            }
            swap(rank,rank2);
        }
        return matrix;
    }
    int find(vector<int> & root, int n){
        if (root[n] != n )
            root[n] = find(root, root[n]);
        return root[n];
    }
};