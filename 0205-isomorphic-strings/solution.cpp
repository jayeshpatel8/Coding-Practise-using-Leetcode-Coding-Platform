class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(256,-1),m2(256,-1);

        for (auto i =0; i<s.size(); i++){
            char c1 = m1[s[i]] ,c2=m2[t[i]];
            if (c1 != c2) return false;
            m1[s[i]]=m2[t[i]]=i;
        }
        return true;
    }
};
