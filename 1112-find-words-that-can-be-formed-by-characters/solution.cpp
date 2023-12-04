class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        vector<int>  f1(26);
        for (auto c : chars) f1[c-'a']++;
        for (auto s : words){
            vector<int>  f(f1);
            bool f2=false;
            for (auto c : s){
                if (--f[c-'a'] < 0){
                    f2=true;
                    break;
                }
            }
            if (!f2) ans += s.size();
        }
        return ans;
    }
};
