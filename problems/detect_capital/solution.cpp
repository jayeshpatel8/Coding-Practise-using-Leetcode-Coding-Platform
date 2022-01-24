class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (auto c : word){
            cnt += c < 'a';
        }
        return (cnt==0 || cnt ==  word.size() || (cnt==1 && word[0]<'a'));
    }
};