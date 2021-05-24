class Solution {
public:
    string toLowerCase(string s) {
        for (int i=0; i<s.size(); i++){
            int c = s[i];
            if (c >='A' && c <='Z'){
                s[i]='a' + (c - 'A');
                
            }      
        }
        return s;
    }
};