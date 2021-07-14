class Solution {
public:
    string customSortString(string order, string str) {
        int freq[26]={};
        for (auto i : str) freq[i-'a']++;
        string ans;
        for (auto c : order)
            if (freq[c-'a']) {
                ans += string(freq[c-'a'],c);
                freq[c - 'a']=0;
            }
        for (int i=0;i<26; i++) 
            if (freq[i])
                ans+=string(freq[i],'a'+i);
        return ans;
    }
};