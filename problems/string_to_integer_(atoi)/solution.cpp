class Solution {
public:
    int myAtoi(string s) {
        int i=0, n  =s.size(), neg=0;
        
        while(i<n && s[i] == ' ') i++;
        
        if (s[i]=='-' || s[i]=='+')
            neg = s[i++]=='-';
        long num=0;
        while(i<n && isdigit(s[i])){
            num = num* 10 + (s[i++]-'0');
            if (num > INT_MAX) break;            
        }
        return neg ? max<long>(INT_MIN, num*-1 ) : min<long>(INT_MAX,num); 
    }
};