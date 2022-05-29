class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int f[26]={},t[26]={};
        for (auto i : s) f[i-'a']++;
        for (auto i : target) t[i-'a']++;
        int ans=INT_MAX;
        for (int i=0; i<26; i++){
            if (t[i])
                ans = min(ans, f[i]/t[i]);
        }
        return ans;
    }
};