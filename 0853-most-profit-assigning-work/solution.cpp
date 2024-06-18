class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<int> idx(d.size());
        iota(begin(idx),end(idx), 0);
        sort(begin(idx),end(idx),[&](auto i, auto j){
            return d[i] < d[j];
        });
        sort(begin(w), end(w));
        int ans = 0, best=0,  m =d.size();
        for (int i=0,j=0; i<w.size(); i++){
            while (j<m && d[idx[j]] <= w[i]){
                best = max(best, p[idx[j++]]);
            }
            ans +=best;
        }
        return ans;
    }
};
