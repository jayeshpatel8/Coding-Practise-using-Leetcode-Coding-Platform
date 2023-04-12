class Solution {
public:
    char repeatedCharacter(string s) {
        int f[128]={};
        for (int i=0; i<s.size(); i++){
            if (f[s[i]]++) return s[i];
        }
        return 'a';
    }
};