class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // if amount is odd and all coins is even ans= 0

        vector<int> dp(amount+1);
        dp[0]=1;
        // 1 2 5  => 5
        for ( auto  c : coins){
            for (int a = 1; a<=amount; a++){
                if (a-c >=0){
                    dp[a] +=dp[a-c];
                }
            }
        }
        return dp[amount];
    }
};