class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size(),idx=0;
        vector<int> prev(n,-1),dp(n,0),ans;
        
        for (int i=1; i<n;i++){
            for (int j=0; j<i; j++){
                if ((nums[i]%nums[j]) == 0){
                    if (dp[i] < (dp[j]+1)){
                        dp[i] = dp[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if (dp[idx]<dp[i]){
                idx=i;
            }            
        }
        while(idx > -1){
            ans.push_back(nums[idx]);
            idx = prev[idx];
        }
        
        return ans;
    }
};
/*
 1 2 4 8
 1
 2 4 8
 
 1 , 
*/