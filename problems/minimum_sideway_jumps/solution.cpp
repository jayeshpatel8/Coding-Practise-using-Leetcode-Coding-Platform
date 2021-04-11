class Solution {
public:
   
    int minSideJumps(vector<int>& ob) {
        int N = ob.size();
        int dp[4]={N,1,0,1};
        for (auto i: ob){
                 
            dp[i]=N;            
            int m = min({dp[1] ,dp[2] ,dp[3] });
            for (int k =1; k<4; k++){
                if (k != i )
                    dp[k] = min(dp[k],m+1);
            }
        }

        return min({dp[1],dp[3],dp[2]});
    }
    
};