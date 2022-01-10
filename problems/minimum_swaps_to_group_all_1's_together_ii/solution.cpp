class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int  i =0 , ans=INT_MAX, n=nums.size() ,t=0,ones=0;
        for (auto j : nums) t += j;
        if (!t || t==n) return 0; 
        for (i=0; i< t; i++) ones += nums[i];
        ans = min(ans, t - ones   );
        for (; i< n; i++){
            ones+=nums[i]-nums[i-t];                        
            ans = min(ans, t - ones   );
        }
         for (i=0; i< t; i++){
            ones+=nums[i]-nums[n+i-t];                        
            ans = min(ans, t - ones   );
        }
        

        return ans;
    }
};