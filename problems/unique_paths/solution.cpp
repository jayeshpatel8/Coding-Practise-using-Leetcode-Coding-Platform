
class Solution {
public:
    int uniquePaths(int c, int r) {

        vector<int> dp(c, 1);
        for (int i = 0; i < r-1; ++i)
            for (int j=1; j<c; j++)
                dp[j] +=dp[j-1];
        return dp[c-1];
    }
};


  
