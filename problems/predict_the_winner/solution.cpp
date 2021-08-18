class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int  N = nums.size();
        if(N <= 1) return true;
        int dp[N][N];
        for ( int i=0; i<N; i++) dp[i][i] = nums[i];
        
        for(int l=1; l<N; l++){
            for (int i=0; i<N-l;i++){
                int j=i+l;
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        return  dp[0][N-1] >= 0 ;
    }
};