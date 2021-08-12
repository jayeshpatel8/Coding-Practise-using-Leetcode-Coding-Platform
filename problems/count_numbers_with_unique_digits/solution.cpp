class Solution {
public:
    int dp[9];
    int countNumbersWithUniqueDigits(int n) {
/*
1
X n=1 => 0-9 = 10 = 9 ^1 + 1
XX n=2 => [1-9 = 9] * [9] => 9 ^ 2 + [0-9] =X
XXX n=3> 9 * 9 * 8 + XX => 9 ^ 2 * 8 + XX
XXXX = 9 *9 * 8 * 7 +XXX  => 9 ^ 2 * 8 * 7 + XXX

*/    
        dp[0]=1; dp[1]=10;       
        for (int i=2, j =9; i<=n;i++){            
            j *= (11-i);  //  9 * 9 * 8 * 7 ...
            dp[i] = j   + dp[i-1];
        }
        return dp[n];
    }
};
