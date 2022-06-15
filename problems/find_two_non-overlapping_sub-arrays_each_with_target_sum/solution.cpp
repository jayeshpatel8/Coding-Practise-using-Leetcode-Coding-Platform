class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int N= nums.size();
        vector<int> dp(N,N);
        int ans = INT_MAX;
        for (int i=N-1, j =i, sum=0; i>=0; i--){
            sum +=nums[i];
            while (sum > target && j>=0 )
                sum -= nums[j--];
            if (sum == target){
                dp[i] = j-i+1;
                if (j+1 <N)
                    ans = min(ans, dp[i] + dp[j+1]);
            }
            if (i<N-1)
                dp[i] = min(dp[i],dp[i+1]);            
        }
 
        return ans >N? -1 : ans;
    }
};