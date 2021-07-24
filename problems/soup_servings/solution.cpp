class Solution {
public:
    int serve[4] = {100,75,50,25};
    vector<vector<double>> dp;
    double soupServings(int n) {
        if( n >= 5000)return 1;
        dp.resize(n+1, vector<double>(n+1,-1));
        return soupServings(n,n);
    }
    
    double soupServings(int A, int B){      
        
        if (A<=0){
            if (B<=0) return 0.5;
            return 1;
        }
        if (B<=0) return 0;
        
        if (dp[A][B]!=-1) return dp[A][B];
        
        double ans=0;
        for (int i=0; i<4; i++)
             ans +=   soupServings(A-serve[i],B-(100-serve[i]));
        return dp[A][B]=ans/4;
    }
};