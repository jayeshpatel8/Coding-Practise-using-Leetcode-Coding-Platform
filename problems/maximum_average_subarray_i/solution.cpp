class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0, sum= 0, N= nums.size();
        double ans = INT_MIN;
       
       for (int i= 0, j=0; i<N; i++ ) {
           sum += nums[i];
           if (i >= k)      
                sum -= nums[j++];            
            
           if (i >=k-1)
                   ans = max(ans, ((double) sum) / k);
        }
        return ans;
    }
};