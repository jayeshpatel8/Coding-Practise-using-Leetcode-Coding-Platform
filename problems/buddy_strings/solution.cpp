class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size()!=goal.size()) return false;
        int f[26]={},c=0;
        for (int i=0,j=-1; i<s.size(); i++){
            f[s[i]-'a']++;
            if (s[i] != goal[i]){
                c++;
                if (c==1){
                    j=i; continue;
                }
                else if (c==2){
                    if (s[j] != goal[i] || s[i] != goal[j]) return false;
                }
                else
                    return false;
            }
        }
        if (c==2) return true;
        if (c==0)
            for (auto i : f) if (i>1) return true;
        return false;
    }
};