class Solution {
public:
    int M , N ,rep = 0, cnt;
    int islandPerimeter(vector<vector<int>>& grid) {
        M =grid.size(), N = grid[0].size();
        for(int i=0;i<M; i++)
            for(int j=0;j<N; j++)
            {
                if (grid[i][j]){
                    cnt++;
                    if (i!=0 && grid[i-1][j]) rep++;
                    if (j!=0 && grid[i][j-1]) rep++;
                }
            }
                    
        return cnt * 4 - rep * 2;
    }

};
