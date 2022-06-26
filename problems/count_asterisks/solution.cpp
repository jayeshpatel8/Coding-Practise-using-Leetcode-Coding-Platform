class Solution {
public:
    int countAsterisks(string s) {
        int i=0, cnt = 0 , ans=0;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '|') cnt++;
            else {
                if (cnt%2 ==0 && s[i] == '*') ans++;
            }
        }
        return ans;
    }
};