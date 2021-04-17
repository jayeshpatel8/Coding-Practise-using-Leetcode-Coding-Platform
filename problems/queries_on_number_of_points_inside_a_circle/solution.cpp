class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto q : queries){
            int  cnt=0;
            auto r2 =  pow(q[2],2);
            for (auto p : points){
                cnt += (pow(q[0] - p[0],2) + pow(q[1] - p[1],2) <=  r2);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};