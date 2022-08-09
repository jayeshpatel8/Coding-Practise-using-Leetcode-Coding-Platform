class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long ans = 0 , mod  = 1e9 + 7;
        unordered_map<int,long> dp;
        sort(begin(arr),end(arr));
        for (int i=0; i<arr.size(); i++){
            int n1 = arr[i];
            long a =1;
            for (int j=0; j<i; j++){
                auto n2 = arr[j];
                if (n1 % n2 == 0)
                    a = (a + dp[n2] * dp[n1/n2])%mod;
            }
            dp[n1] = a;
            ans = (ans + a)%mod;
        }
        
        return ans ;
    }
};