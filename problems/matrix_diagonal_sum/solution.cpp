class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0, N= mat.size();
        for (int i=0,j=0; i<N; i++,j++)   {
            ans += mat[i][j] + mat[i][N-j-1];
        }
        return ans - (N &1 ? mat[N/2][N/2] : 0);
    }
};