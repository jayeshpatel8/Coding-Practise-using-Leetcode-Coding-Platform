class Solution {
public:
    int minSteps(string s, string t) {
    // abb aab
    // cdeeelot
    // acceiprt
        int cnt[26]={};
        for (auto c : t)      cnt[c-'a']++;
        for (auto c : s)      cnt[c-'a']--;
        
        int ans = 0;
        for (auto d : cnt){
            if (d > 0) ans += d;
        }
        return ans;
    }
};
