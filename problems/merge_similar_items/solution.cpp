class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int w[1001]={};
        for (auto i : items1)
            w[i[0]]+=i[1];
        for (auto i : items2)
            w[i[0]]+=i[1];
        vector<vector<int>> ans;
        for (int i=1; i<1001; i++){
            if (w[i]){
                ans.push_back({i,w[i]});
            }
        }
        return ans;
    }
};