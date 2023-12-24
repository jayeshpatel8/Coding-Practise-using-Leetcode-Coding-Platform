class Solution {
public:
    int minOperations(string s) {
        int dp[2]={}, ch=0;

        for (auto c : s)
            dp[ ((ch++ & 1) == c-'0')]++;
            
        return min(dp[0], dp[1]);
    }
};
