class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0,j=0;
        int star=0,ss;
        while(s[i])
        {
            if ( s[i]==p[j] || p[j]=='?') { i++;j++; }
            else if (p[j]=='*'){ star=++j; ss=i;}
            else if (star) {i=++ss;j=star;}
            else return false;
        }
        while(p[j] && p[j]=='*') {j++;continue;}
            
        return !p[j];
    }
};