class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int j=-1;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '1') 
                s[i]='0', s[++j] = '1';
        }
        s[j]='0';
        s[s.size()-1]='1';
        return s;
    }
};
