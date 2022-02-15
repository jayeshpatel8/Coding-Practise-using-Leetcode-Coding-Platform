class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int N = nums.size(), sum=0, ans = 0, mi=INT_MAX, ma=INT_MIN,  inc =0;
        for (int i=0; i<N-1; i++){
            int a= nums[i] ,b = nums[i+1], diff = abs(a-b);
            sum += diff;
            // prefix arr till a revert
            inc = max(inc, -diff + abs(nums[0]-b) );
            // suffix arr till b revert
            inc = max(inc, -diff + abs(nums[N-1]-a) );
            // inbetween
            mi=min(mi,max(a,b));
            ma=max(ma,min(a,b));
        }
        return sum + max(inc, 2 * (ma-mi));
    }
};