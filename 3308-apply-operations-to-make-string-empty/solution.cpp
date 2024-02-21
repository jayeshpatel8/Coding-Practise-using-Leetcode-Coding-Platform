class Solution {
public:
    string lastNonEmptyString(string s) {
        int f[26]={},f2[26]={};
        for (auto c: s) f[c-'a']++;
        int m = *max_element(begin(f),end(f));
        string ans;
        for (auto c: s){
            f2[c-'a']++;
            if (f2[c-'a']==m) ans.push_back(c);
        }
        return ans;
    }
};
