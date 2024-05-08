class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> idx(score.size());
        iota(begin(idx),end(idx),0);
        sort(begin(idx), end(idx), [&](auto i, auto j){ return score[i] > score[j];});
        int i = 0, n = score.size();
        vector<string> ans(n);
        ans[idx[i++]] = "Gold Medal";
        if (i <n) ans[idx[i++]] = "Silver Medal";
        if (i <n) ans[idx[i++]] = "Bronze Medal";
        for (; i<n; i++)
            ans[idx[i]] = to_string(i+1);
        return ans;
    }
};
