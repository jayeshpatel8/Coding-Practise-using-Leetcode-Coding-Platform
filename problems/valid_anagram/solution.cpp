class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> A(26);
        for (auto &c : s) A[c-'a']++;
        for (auto &c : t) A[c-'a']--;
        return count(begin(A),end(A),0)==26;
    }
};