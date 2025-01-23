class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r[250]={}, c[250]={}, ans=  0;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size();j++)
                if (grid[i][j])
                    r[i]++,c[j]++;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size();j++)
                if (grid[i][j])
                    ans += r[i] > 1 || c[j] > 1;
        return ans;
    }
};
