class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int dp[arr.size()];
        dp[0] = arr[0];
        
        for (int i=1; i<arr.size(); i++){
            int m=-1, sum=0;
            for (int j=i; i-j<k && j>=0; j--){
                m = max(m, arr[j]);                
                sum = max(sum, (i-j+1) * m + (j>0 ? dp[j-1] : 0 ) );
            }
            dp[i] = sum;
        }
        return dp[arr.size()-1];
    }
};