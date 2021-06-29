class Solution {
public:
    string removeDuplicates(string s) {
        int j=1;
        for (int i=1; i<s.size(); i++,j++){
            // "abbaca"
            s[j]=s[i];
            if (j>0 && s[j]==s[j-1]) j-=2;            
        }
        return s.substr(0,j);
    }
};