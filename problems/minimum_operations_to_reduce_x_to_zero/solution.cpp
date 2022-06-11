class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum1 = accumulate(begin(nums), end(nums),0)-x, sum=0;
        int ans = INT_MAX, N = nums.size(), l=0, r =0;
        while ( l<=r ){
            if (sum <= sum1){
                if (sum == sum1) ans = min(ans, l+N-r);
                
                if (r <N) sum +=nums[r++]; 
                else break;
                
            }
            else
                sum -=nums[l++];
        }
        return ans ==INT_MAX ? -1 : ans;
    }
};