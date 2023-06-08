class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int M  = grid.size(), N =  grid[0].size();
        if (grid[M-1][N-1]>=0) return 0;
        int ans = 0,i=0,j=N-1;
        while (i<M && j>=0){
            if (grid[i][j] < 0)
                ans += M-i,j--;
            else i++;
        }
        return ans;
    }
};