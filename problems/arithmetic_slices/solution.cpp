class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        
        for ( int i=2, p = 0;i<nums.size(); i++){
            if (nums[i-2]-nums[i-1] == nums[i-1]-nums[i]){
                ans += ++p;
            }
            else
                p=0;
        }
        return ans;
    }
    int numberOfArithmeticSlices2(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N,0);
        for ( int i=2;i<N; i++){
            if (nums[i-2]-nums[i-1] == nums[i-1]-nums[i]){
                if (dp[i-1])
                    dp[i] = dp[i-1];
                dp[i] += 1;
            }
        }
        return accumulate(begin(dp), end(dp),0);
    }    
};