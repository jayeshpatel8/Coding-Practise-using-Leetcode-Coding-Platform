class Solution {
public:
    string smallestString(string s) {
        int c=0;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='a'){
                if (c==0) continue;
                return s;
            }
            else
                c=1,s[i]--;
        }
        if (c==0) s.back()='z';
        return s;
    }
};