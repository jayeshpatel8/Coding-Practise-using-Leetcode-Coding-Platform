class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26),f2(26);
        for (auto c : word1) f1[c-'a']++;
        for (auto c : word2) f2[c-'a']++;
        for(int i=0;  i<26;i++)
            if (!f1[i] != !f2[i])
                return false;
        sort(begin(f1),end(f1));
        sort(begin(f2),end(f2));
        return f1==f2;
    }
};
