class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<array<int,2>> st;
        for (int j =0; j<mat.size(); j++){
            int cnt = 0;
            for (auto &i : mat[j]){
                if (i) cnt++ ;
                else break;
            }
            st.insert({cnt,j});
        }
        vector<int> ans;
        for ( auto & s : st){
            if (k-- > 0){
                ans.push_back(s[1]);
            }
        }
        return ans;
    }
};