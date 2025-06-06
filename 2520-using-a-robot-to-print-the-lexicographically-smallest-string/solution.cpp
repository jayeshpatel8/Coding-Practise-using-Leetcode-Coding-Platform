class Solution {
public:
    string robotWithString(string s) {
        int f[26]={0} , ch='a';
        for (auto c : s)f[c-'a']++;
        string t, ans;
        for (auto c :s){
            t+=c;
            f[c-'a']--;
            while (ch<='z' && f[ch-'a']==0) ch++;

            while (!t.empty() && t.back() <= ch){
                ans +=t.back(); t.pop_back();
            }

        }
        return ans;
    }
};
