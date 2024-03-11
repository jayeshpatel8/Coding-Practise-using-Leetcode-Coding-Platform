class Solution {
public:
    string customSortString(string order, string s) {
        int sf[26]={};
        for (auto c : s) sf[c - 'a']++;
        string ans;
        for (auto c : order){
            if (sf[c-'a']) ans += string(sf[c-'a'],c);
            sf[c-'a']=0;
        }
        for (auto i=0; i<26; i++) if (sf[i]) ans +=string(sf[i], i+'a');

        return ans;
    }
};
