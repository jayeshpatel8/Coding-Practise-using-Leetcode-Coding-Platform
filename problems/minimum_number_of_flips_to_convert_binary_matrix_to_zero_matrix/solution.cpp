class Solution {
public:
    int N,M;
    int minFlips(vector<vector<int>>& mat) {
        N = mat.size(), M = mat[0].size();
        int ans ;

        ans=(dfs(mat, 0, 0));
        return ans>= 1e5 ? -1 : ans;
    }
    int dfs(vector<vector<int>> mat, int r, int c) {        
        if (c==M) c=0,r++;
        if (r ==N) return Iszero(mat) ? 0 : 1e5;              
        return min(  dfs(mat, r,c+1), 1 + dfs(flip(mat,r,c), r,c+1)  ); 
    }
    vector<vector<int>>&  flip (vector<vector<int>>& mat, int r, int c){
        mat[r][c] ^=1;
        if (r+1 < N) mat[r+1][c] ^=1;
        if (c+1 < M) mat[r][c+1] ^=1;
        if (r-1 >= 0) mat[r-1][c] ^=1;
        if (c-1 >= 0) mat[r][c-1] ^=1;
        return mat;
    }
    bool Iszero(vector<vector<int>>& mat){
        for ( auto &i : mat)
            for (auto j : i)
                if (j)
                    return false;
        
        return true;
    }
};