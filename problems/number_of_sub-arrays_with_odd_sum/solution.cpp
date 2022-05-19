class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        //        [1,2,3,4,5,6,7]
        // odd  0  1 1 2 2 3 3 4 
        // even 0  0 1 1 2 2 3 3
        //vector<array<int,2>> dp(arr.size()+1);
        int ans = 0, mod = 1e9 + 7, even=0,odd=0;
        for (int i=0; i<arr.size(); i++){
            auto n = arr[i];
            /*
            if (n & 1){
                dp[i+1][1] = 1 + dp[i][0];
                dp[i+1][0] = dp[i][1];
            }
            else{
                dp[i+1][1] = dp[i][1];
                dp[i+1][0] = 1 + dp[i][0];
            }
            ans  = (ans + dp[i+1][1])%mod;
            */
            if (n & 1){
                swap(odd,even); odd++;
            }
            else  
                even++;
            ans  = (ans + odd)%mod;
        }
        return ans;
    }
};