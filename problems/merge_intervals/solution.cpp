class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        vector<vector<int>> ans;
        sort(begin(intv), end(intv), [](auto &i, auto &j){ return i[0] < j[0];});
        
        int s = intv[0][0], e = intv[0][1];
        for (int i=1; i<intv.size(); i++){
            if (intv[i][0] > e){
                ans.push_back({s,e});
                s = intv[i][0] , e = intv[i][1];
            }else{
                e = max(e,intv[i][1]); 
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};