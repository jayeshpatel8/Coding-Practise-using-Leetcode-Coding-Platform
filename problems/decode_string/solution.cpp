class Solution {
public:
    string decodeString(string s) {
        if (s.size()){
            
            if (isdigit(s[0])){
                int i=0, rep = 0;;
                while(i <s.size() && isdigit(s[i])) {
                    rep = rep * 10 + s[i] - '0';
                    i++;
                }      
                if (i == s.size()) return s;
                int start=0, j = i;
                while(j < s.size()){
                    if(s[j] == '[') start++;
                    else if(s[j] == ']') start--;
                    if (start ==  0) break;
                    j++;
                }
                string s1 = decodeString(s.substr(i+1,j-i-1));
                string ans;
                while(rep-- > 0) ans += s1;
                return ans + (j<s.size() ? decodeString(s.substr(j+1)) : "");
                
            }
            else{
                int i=1;//, rep = 0;;
                while(i <s.size() && isalpha(s[i])) {
                    //rep = rep * 10 + s[i] - '0';
                    i++;
                }
                return s.substr(0,i) + decodeString(s.substr(i));
            }
        }
        return s;
    }
};