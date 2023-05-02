class Solution {
public:
    int appendCharacters(string s, string t) {
        for (int i=0, j=0; 1 ; i++){
            if (j==t.size()) return 0;
            if (i==s.size()) return t.size()-j;
            if (s[i]==t[j]) j++;
        }
        return 0;
    }
};