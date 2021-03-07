class Solution {
public:
    int trie[2000*7+1][26];
    int idx=0;
    bool trieInsert(string &s){
        int i = s.length()-1;
        int j=0;
        bool res=true;
        for (; i>=0; i--){
            int c = s[i]-'a';
            if (trie[j][c]==0){
                trie[j][c] = ++idx;
                res=false;
            }
            j = trie[j][c];
        }
        return res;
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto &s1, auto &s2){return s1.length()>s2.length();});
        int len=0;
        for (auto s : words){
            if (!trieInsert(s)) len += s.length()+1;
        }
        return len;
    }
};