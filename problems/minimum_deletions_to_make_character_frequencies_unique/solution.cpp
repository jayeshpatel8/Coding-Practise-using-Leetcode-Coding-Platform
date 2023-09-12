class Solution {
public:
    int minDeletions(string s) {
        int ans = 0, f[26]={};
        for (auto c : s) f[c-'a']++;
        vector<int> cnt(1e5 + 1);
        for (auto c : f) cnt[c]++;
        for (int i=1e5; i>0; i--){
            if (cnt[i] <=1) continue;
            ans += cnt[i]-1;
            cnt[i-1] += cnt[i]-1;
        }
        return ans;
    }
};