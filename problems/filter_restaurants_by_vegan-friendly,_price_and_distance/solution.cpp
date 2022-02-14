class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& res, int veg, int mp, int md) {
        vector<vector<int>>ans;
        for (int i=0; i< res.size(); i++){
            if (veg){
                if (res[i][2]==0) continue;
            }
            if (res[i][3] > mp || res[i][4] > md) continue;
            ans.push_back(res[i]);
        }
        sort(begin(ans),end(ans),[](auto & a,auto &b){
            if (a[1]!= b[1]) return a[1] > b[1];  
            return a[0] > b[0];
        });
        vector<int> a;
        for (auto & i : ans) a.push_back(i[0]);
        return a;
    }
};