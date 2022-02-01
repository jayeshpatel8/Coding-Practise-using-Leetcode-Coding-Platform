class Solution {
public:
    int minSteps(string s, string t) {
        int freq1[26] = {}, freq2[26] = {};
        for (auto c : s) freq1[c-'a']++;
        for (auto c : t) freq2[c-'a']++;
        int same = 0;
        for (int i=0; i<26; i++)
            same += min(freq1[i], freq2[i]);
        return s.size()-same;
    }
};