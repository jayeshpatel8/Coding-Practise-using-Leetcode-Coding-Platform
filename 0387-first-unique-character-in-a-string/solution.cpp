class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26,1e5);
        for (auto i=0; i< s.size(); i++) if (f[s[i]-'a'] == 1e5) f[s[i]-'a']=i;
        else f[s[i]-'a']=1e5+1;
        auto ans= *min_element(begin(f),end(f));
        return ans >= 1e5 ? -1 : ans;
    }
};
