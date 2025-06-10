class Solution {
public:
    int maxDifference(string s) {
        int f[26]={};
        for (auto c: s ) f[c-'a']++;
        int o=0,e=1e8;
        for (auto c : f){
            if (!c) continue;
            if (c & 1) o = max(o,c);
            else e = min(e,c);
        }
        return o-e;
    }
};
