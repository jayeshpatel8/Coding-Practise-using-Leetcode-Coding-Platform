class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        vector<vector<int>>dp(M,vector<int>(N));
        vector<int> row(M), col(N);

        map<int,vector<int>> sorted;
        for (int i=0;i<M; i++)
            for (int j=0; j<N;j++)
                sorted[mat[i][j]].push_back(i*N+j);
        for (auto & [_ , idx] : sorted){
            for (auto v : idx){
                int i = v/N , j =  v%N;
                dp[i][j] = max(row[i], col[j]) + 1;
            }
            for (auto v : idx){
                int i = v/N , j =  v%N;
                row[i] = max(row[i], dp[i][j]);
                col[j] = max(col[j], dp[i][j]);
            }
        }
        return max(*max_element(begin(row),end(row)),*max_element(begin(col),end(col)));
    }
};
