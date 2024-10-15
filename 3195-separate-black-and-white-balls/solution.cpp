class Solution {
public:
    long long minimumSteps(string s) {
        long  long ans = 0;
        for (int i=0, c=0; i<s.length(); i++){
            if (s[i] =='0'){
                ans += c;
            }
            else c++;
        }
        return ans;
    }
};
