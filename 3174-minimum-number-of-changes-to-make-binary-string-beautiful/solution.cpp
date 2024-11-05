class Solution {
public:
    int minChanges(string s) {
        int ans = 0 ,i= 0;
        for (; i<s.size(); i+=2){
            ans += (s[i] != s[i+1]);
        }
        
        return ans;
    }
};
