class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), end(items));
        
        vector<vector<int>> quers;
        for (int i=0; i< queries.size(); i++)
            quers.push_back({queries[i],i});
        sort(quers.begin(), end(quers));
        
        int max_n = 0;
        vector<int>  ans(queries.size());
        for (int i=0, j = 0; i<quers.size(); i++){
            while (j < items.size() && items[j][0] <= quers[i][0])
                max_n = max(max_n, items[j++][1]);
            ans[quers[i][1]] = max_n;
        }
        return ans;
    }
};