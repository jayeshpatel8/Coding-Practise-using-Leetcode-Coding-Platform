class Solution {
public:
    string reverseWords(string s) {
        string s1;
        for (int i=0; i<s.size(); ){
            if (s[i] == ' ') { i++; continue;}
            else{
                int j=i;
                string s2;
                while(j<s.size() && s[j] != ' ') s2.push_back(s[j++]);
                reverse(s2.begin(), s2.end());
                s1 += s2 + " ";
                i=j;
            }
        }
        s1.pop_back();
        reverse(s1.begin(),s1.end());
        return s1;
    }
};