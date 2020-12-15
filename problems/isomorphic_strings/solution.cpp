class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int cnt[256]={};
        int cnt2[256]={};
        for(int i=0;  i< s.length(); i++) {
            int a = s[i], b= t[i];
            if (cnt[a] != cnt2[b]) return false;
             cnt[a]=cnt2[b]=i+1;
        }
        return true;
    }
};