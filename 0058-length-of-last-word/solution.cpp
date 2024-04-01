class Solution {
public:
    int lengthOfLastWord(string s) {
        int l=s.size();
        int i=l-1;
        for (; i>=0;i--)
            if (s[i]==' '){
                if (i==l-1) {l=i;
                    continue;}
                break; 
            }
        return l-i-1;
    }
};
