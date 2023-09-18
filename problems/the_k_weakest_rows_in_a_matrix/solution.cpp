class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> cnt;
        for (auto &i : mat){
            int c = 0;
            for (auto j : i) c+=j;
            cnt.push_back(c);
        }
        vector<int> idx(cnt.size()),ans;
        iota(begin(idx),end(idx),0);
        sort(begin(idx),end(idx),[&](int a, int b){return cnt[a]==cnt[b] ? a < b : cnt[a]<cnt[b];});
        idx.resize(k);
        return idx;
    }
};