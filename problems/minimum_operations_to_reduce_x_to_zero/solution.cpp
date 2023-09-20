class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum1 = accumulate(begin(nums), end(nums),0)-x, sum=0;
        int ans = -1, N = nums.size(), l=0, r =0;
        while ( r<N ){
            sum +=nums[r]; 
            while(sum > sum1 && l<=r)
                sum -=nums[l++];
            
            if (sum == sum1) ans = max(ans, (r-l+1));
            r++;
        }
        return ans==-1?ans:N-ans;
    }
};