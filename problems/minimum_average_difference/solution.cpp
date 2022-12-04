class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size() ,avg =INT_MAX, ans = 0;
        long sum=0,lsum=0;
        for (auto i : nums) 
           sum += i;

        for (int i=0,j = n-i-1; i<n-1; i++,j--){
            lsum += nums[i];
            auto d = abs(lsum/(i+1) - (sum-lsum)/j);
            if ( d < avg)
                avg=d, ans = i;
        }
        if ( avg > sum/n) ans = n-1;
        return ans;
    }
};