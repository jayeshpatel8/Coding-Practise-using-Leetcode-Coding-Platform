class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s1(26),t1(26);
        for (auto c : s) s1[c-'a']++;
        for (auto c : t) t1[c-'a']++;
        return s1==t1;
    }
};