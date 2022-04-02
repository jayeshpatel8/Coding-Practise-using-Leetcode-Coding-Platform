class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        auto isPal = [&]( int l, int r){
            while (l<r)
                if (s[l++] != s[r--]) return false;            
            return true;            
        }; 
        while (l <r){
            if (s[l] != s[r]){
                if (isPal(l+1,r) || isPal(l,r-1) )
                    return true;
                else
                    return false;
            }
            else
                l++,r--;
        }
        return true;
    }
};