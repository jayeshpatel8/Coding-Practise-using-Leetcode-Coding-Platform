class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int f[26]={};
        for (auto i : s) f[i-'a']++;

        int ans = 0, mod = 1e9 + 7, idx = 25;
        for (int j=0; j<t; j++){
            f[(idx + 1) %26] = (f[(idx + 1) %26] + f[idx]) %mod;
            idx = (idx - 1 + 26) % 26;
        }
        for (auto i : f) ans = (ans + i) % mod;
        return ans ;
    }
};
