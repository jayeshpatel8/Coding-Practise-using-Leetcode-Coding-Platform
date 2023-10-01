class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        for (int i=1,j=0; i<s.size(); i++){
            if (s[i]==' '){            
                reverse(begin(s)+j, begin(s)+i);
                j=i+1;
            }
        }
        s.pop_back();
        return s;
    }
    string reverseWords2(string s) {
        int i=0,j=0;
        for (; i<s.size(); i++){
            if (s[i]==' '){
                if (s[j] != ' '){
                    reverse(begin(s)+j, begin(s)+i);
                }
                j=i+1;
            }
            else {
                if (s[j]==' ')j=i;
            }
        }
        if (j<s.size()) reverse(begin(s)+j, begin(s)+i);
        return s;
    }
};