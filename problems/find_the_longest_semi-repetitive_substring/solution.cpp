class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1;
        for (int i=0, j =i+1 ,c  = 0; j<s.size(); j++){
            if (s[j]==s[j-1]) c++;
            while (c >1 && i <j)
                c -= s[i]==s[i+1], i++;
            ans = max(ans, j-i+1);
        }
        return ans;
    }
    int longestSemiRepetitiveSubstring2(string s) {
        int ans = 1;
        for (int i=0; i<s.size(); i++){
            int cnt=0;
            for (int j = i+1; j<s.size() ; j++){
                cnt +=(s[j] == s[j-1]);
                if(cnt < 2) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};