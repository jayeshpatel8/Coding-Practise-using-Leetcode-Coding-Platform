class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> edge(n, vector<bool>(n));
        vector<int> indeg(n);
        for (auto & r : roads)
            edge[r[1]][r[0]]=edge[r[0]][r[1]]=true, indeg[r[0]]++, indeg[r[1]]++;
        int ans=0;
        for (int a=0; a<n;a++){
            for (int b=a+1; b<n; b++){
                int sum = indeg[a]+ indeg[b]-edge[a][b];
                ans= max(ans, sum);
            }

        }
        return ans;
    }
};