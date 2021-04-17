class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if ( n == 1) return 0;
        uint64_t ans=0;
        int cur=nums[0];
        for (int i=1; i<n; i++){
            if (cur < nums[i] ){
                cur = nums[i];
            }
            else{
                ans += cur - nums[i] + 1;
                cur +=1;
            }
        }
        return ans;
    }
};