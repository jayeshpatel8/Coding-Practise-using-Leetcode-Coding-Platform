class Solution {
public:
    int removePalindromeSub(string s) {
     int sz = s.length();
        if (!sz  ) return 0;
        for(int i=0,j=sz-1; i<j; i++) if(s[i]!=s[j--]) return 2;
        return 1;
    }
};