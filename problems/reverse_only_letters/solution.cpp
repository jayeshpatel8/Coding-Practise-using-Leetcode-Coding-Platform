class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start=0, end=s.size()-1;
        while(start < end){
            if (!isValid(s[start] )) start++;
            else if (!isValid(s[end] )) end--;
            else
                swap(s[start++], s[end--]);            
        }
        return s;
    }
    bool isValid(char c){
        return (c >= 'a' && c <='z') || (c >='A' && c <='Z');
    }
};