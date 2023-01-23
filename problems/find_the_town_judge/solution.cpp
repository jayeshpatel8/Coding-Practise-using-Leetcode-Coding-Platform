class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n+1);
        for (auto & t : trust){
            cnt[t[0]]--;
            cnt[t[1]]++;
        }
        for (int i=1;i<=n; i++)
            if (cnt[i]==n-1) return i;
        return -1;
    }
};