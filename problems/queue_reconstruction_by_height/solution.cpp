class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(begin(p),end(p),[](auto &a, auto &b){ return a[0] > b[0]  || (a[1]  <b[1] && a[0] ==b[0]);});
        vector<vector<int>>  ans;
        
        for (auto & i : p){
            ans.insert(begin(ans) + i[1], i);
        }
        return ans;
    }
};