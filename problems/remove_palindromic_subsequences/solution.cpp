class Solution {
public:
    int removePalindromeSub(string s) {
    
        
        return 1 + (isPal(s)==false);
    }
    bool isPal(string s){
        for (int i=0, j=s.size()-1; i<j; i++,j--){
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};