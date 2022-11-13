class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for (int i=0; i<s.size(); i++){
            if (s[i] == ' ') continue;
            int j = i;
            while (j<s.size() && s[j] != ' ')
            {
                j++;
            }
            reverse(begin(s)+i,begin(s)+j);
            
            ans += s.substr(i, j-i) + ' ';
            i=j;
        }
        ans.pop_back();
        reverse(begin(ans),end(ans));
        return ans;
    }
};