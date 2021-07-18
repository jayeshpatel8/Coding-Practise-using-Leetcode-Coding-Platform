class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& M) {
        int N = M.size();
        
        for (int i=N-2; i>=0; i--)
            for (int j=0; j<N; j++)
                M[i][j] += min({M[i+1][j], M[i+1][max(0,j-1)], M[i+1][min(N-1,j+1)]});
        return *min_element(begin(M[0]),end(M[0]));
    }
};