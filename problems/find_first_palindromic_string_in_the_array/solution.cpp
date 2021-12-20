class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for (int i=0; i<n; i++)
            if (isPal(words[i]))
                return words[i];
        return "";        
    }
    bool isPal(string &s){
        int i =0, j=s.size()-1;
        while (i<j && s[i] == s[j]) i++,j--;
        return i>=j;
    }
};