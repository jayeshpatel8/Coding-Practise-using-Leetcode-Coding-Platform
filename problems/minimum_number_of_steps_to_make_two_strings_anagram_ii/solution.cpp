class Solution {
public:
    int minSteps(string s, string t) {
        int f1[26]={},f2[26]={};
        for (auto c : s) f1[c-'a']++;
        for (auto c : t) f2[c-'a']++;
        int ans=0;
        for (int i=0; i<26; i++){
            if (f1[i] && f2[i]){
                ans += abs(f1[i] -f2[i]);
            }
            else
                ans += (f1[i] + f2[i]);
        }
        return ans;
    }
};