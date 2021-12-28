class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size() , ans = 0;

        
        for ( int i=0; i<m; i++){
            vector<int> row(n,1);
            for ( int i1=i; i1<m; i1++){
                for ( int j=0; j<n; j++){
                    row[j] &= mat[i1][j];
                }
                for (int j=0, len=0; j<n; j++)
                    ans += row[j] ? ++len : len=0;
            }
        }

        return ans;
    }
};