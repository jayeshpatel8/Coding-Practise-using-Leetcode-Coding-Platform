class Solution {
public:
    int dp[20][2001];
    int findTargetSumWays(vector<int>& nums, int target) {
        dp[0][nums[0]+1000]=1;
        dp[0][-nums[0]+1000]+=1;
        for (int i = 1; i< nums.size(); i++){
            for (int sum=-1000; sum<=1000; sum++){
                if (dp[i-1][sum + 1000 ]){
                    dp[i][sum + 1000 + nums[i]] += dp[i-1][sum + 1000 ];
                    dp[i][sum + 1000 - nums[i]] += dp[i-1][sum + 1000 ];
                }
            }
        }
        return dp[nums.size()-1][target+1000];
    }
    int ways(vector<int>& nums, int target, int i){
        if (i<0) return 0 == target;
         //long k = target | ((long)i<<32);
        //if (m.count(k))return m[k];
        return ways(nums,target+nums[i],i-1) + ways(nums,target-nums[i],i-1); 
    }
};
/*
    1 1 1 -1 -1
*/