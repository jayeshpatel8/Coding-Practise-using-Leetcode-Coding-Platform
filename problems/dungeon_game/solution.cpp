class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(),n = dungeon[0].size();
        vector<vector<int>> cost(m+1,vector<int>(n+1,INT_MAX));
        cost[m][n-1]=cost[m-1][n]=1;
        for (int i=m-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                    cost[i][j] = min(cost[i+1][j],  cost[i][j+1]) - dungeon[i][j];
                    if (cost[i][j] < 1) cost[i][j] = 1;    
            }
        }
        return cost[0][0];
    }
};