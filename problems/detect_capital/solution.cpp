class Solution {
public:
    bool detectCapitalUse(string word) {
        bool cap = isupper(word[0]);
        int c=0;
        for (auto i : word)
            if(isupper(i)) c++;
        return c == 1 ? cap : (c==0 || c==word.size());
    }
};