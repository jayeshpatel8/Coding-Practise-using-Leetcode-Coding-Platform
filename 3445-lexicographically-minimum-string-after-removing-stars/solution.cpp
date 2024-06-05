class Solution {
public:
    string clearStars(string s) {
        vector<int> ch[26];
        for (auto i =0; i<s.size();  i++){
            auto c = s[i]-'a';
            if (s[i] != '*')
                ch[c].push_back(i);
                else{
                    for (int j=0; j<26; j++){
                        if (!ch[j].empty()) {
                            s[ch[j].back()]='*';
                            ch[j].pop_back();
                            break;
                        }
                    }
                }
        }
        string ans;
        for (auto c : s){
            if (c != '*') {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
