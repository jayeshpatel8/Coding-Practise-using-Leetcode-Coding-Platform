class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[128]={};
        for (auto c : s) cnt[c]++;
        for (int i=0; i<s.size(); i++)
            if (cnt[s[i]]==1) return i;
        return -1;
    }
};