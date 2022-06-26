class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int M=grid.size(), N= grid[0].size();
        for (int l=0,r=N-1; l<=r; l++,r--){
            if (grid[l][l]==0 ||grid[l][r] ==0 || grid[r][l]==0||grid[r][r]==0) return false;
            if (l==r) break;
            for (int k=l+1; k<r; k++)
                if (grid[l][k])return false;
            for (int k=l+1; k<r; k++)
                if (grid[r][k])return false;
            for (int k=l+1; k<r; k++)
                if (grid[k][l])return false;
            for (int k=l+1; k<r; k++)
                if (grid[k][r])return false;
        }
        return true;
    }
};