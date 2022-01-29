class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0 , M = grid.size(), N = grid[0].size(), i = 0, j =  N-1;
        while (j>=0 && i<M){
            if (grid[i][j] < 0 ) 
                ans += M-i, j--;
            else                
                i++;   
        }       
        return ans;
    }
};