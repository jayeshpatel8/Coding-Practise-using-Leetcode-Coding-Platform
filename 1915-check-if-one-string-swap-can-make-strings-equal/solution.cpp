class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int f[26]={};
        for (auto c : s1) f[c-'a']++;
        for (auto c : s2) f[c-'a']--;

        for (auto i : f) if (i != 0) return false;

        int ch=0, j=-1;
        for (int i=0; i<s1.size(); i++){
            if (s1[i] != s2[i]){
                ch++;
                if (j != -1){
                    if ((s1[j] != s2[i]) || (s1[i] != s2[j] )) return false;
                    j=-1;
                }
                else j=i;
            }
        }
        return ch > 2 ? false: true;
    }
};
