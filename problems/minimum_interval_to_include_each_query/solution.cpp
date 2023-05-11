class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intv, vector<int>& queries) {
        sort(begin(intv),end(intv));
        vector<int> ids(queries.size());
        iota(begin(ids),end(ids),0);
        sort(begin(ids),end(ids),[&](auto a, auto b){ return queries[a] < queries[b];});
        vector<int> ans(queries.size(),-1);
        set<array<int,2>> st;
        int j=0;
        for (auto i : ids) {
            int q = queries[i];
            while (j<intv.size() && intv[j][0] <= q){
                st.insert({intv[j][1] - intv[j][0] + 1,  intv[j][1]}); j++;}
            while (!st.empty() && (*begin(st))[1] < q)
             st.erase(begin(st));
            if (!st.empty())
                ans[i] = (*begin(st))[0];
        }
        return ans;
    }
};