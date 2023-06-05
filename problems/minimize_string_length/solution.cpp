class Solution {
public:
    int minimizedStringLength(string s) {
        int f[26]={};
        for (auto c : s) f[c-'a']++;
        return count_if(begin(f),end(f),[&](int a){ return a > 0;});
    }
};