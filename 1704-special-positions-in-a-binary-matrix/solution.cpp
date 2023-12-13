class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r[100]={}, c[100]={};
        for (int i=0; i<mat.size(); i++){
            for (int j=0; j<mat[0].size(); j++)
                r[i] += mat[i][j],c[j] += mat[i][j];
        }
        int ans=0;
        for (int i=0; i<mat.size(); i++){
            if (r[i]!=1 ) continue;
            for (int j=0; j<mat[0].size(); j++)
                if (mat[i][j] ==1 && c[j]==1 ) ans++;
        }

        return ans;
    }
};
