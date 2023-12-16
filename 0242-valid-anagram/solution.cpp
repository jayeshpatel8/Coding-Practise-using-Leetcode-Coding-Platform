class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26]={};
        for (auto c: s) cnt[c-'a']++;
        for (auto c: t) cnt[c-'a']--;
        for (auto i : cnt) if (i != 0) return false;
        return true;
    }
};
