class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int ch[256];
        for (int i='a'; i<'a'+26; i++) ch[i]=0;
        for (int i=0; i<s.size(); i++) {
            ch[s[i]]++;
            ch[t[i]]--;
        }
        for (int i='a'; i<'a'+26; i++) if (ch[i]) return false;
        return true;
    }
};