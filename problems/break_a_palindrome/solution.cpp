class Solution {
public:
    string breakPalindrome(string pal) {
        int i=0, N = pal.size()/2;
        if (N==0) return "";
        for (; i< N; i++)
            if ('a' != pal[i]){ 
                pal[i] = 'a';
                return pal;
            }
        pal[pal.size()-1]='b';
        return pal;
    }
};