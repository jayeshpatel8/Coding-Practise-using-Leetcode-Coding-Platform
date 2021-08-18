class Solution {
public:
    double dp[100][100]={};
    double largestSumOfAverages(vector<int>& nums, int K, int i=0) {
        if (i >= nums.size() || dp[i][K] > 0 ) return dp[i][K];
        double ans= 0, sum = 0;
        if(K==1){
            for(int j = i; j<nums.size(); j++)
                sum +=nums[j];
            return dp[i][K] = sum / (nums.size()-i);
        }
        for(int j = i; j<=nums.size()-K; j++){
            sum +=nums[j];
            ans = max (ans ,(sum)/(j-i+1)+ largestSumOfAverages(nums,K-1,j+1));
        }

        return dp[i][K] = ans;
    }
};

