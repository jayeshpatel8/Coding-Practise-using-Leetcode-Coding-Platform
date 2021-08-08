
class Solution {
public:
    int dp[200][200] , N ;
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        N = nums.size();
        return loss(nums, 0,k);
    }
    int loss(vector<int>& nums, int i, int k){
        if(i==N ) return 0;
        if (k == -1) return 1e8;
        if (dp[i][k] != -1) return dp[i][k];
        int sum=0,maxn=nums[i],ans=INT_MAX;
        for ( int j = i; j<N; j++){
            maxn = max(maxn, nums[j]);
            sum += nums[j];
            int diff = maxn * (j-i+1) - sum;
            ans =  min ( ans,  diff + loss(nums,j+1,k-1));
        }
        return dp[i][k] = ans;
        
    }
};
