class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto i = word.find(ch);
        if ( i == string::npos) return word;  
        reverse(begin(word),begin(word)+i+1);
        return word;
    }
};