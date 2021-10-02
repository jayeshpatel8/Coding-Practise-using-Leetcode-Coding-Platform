class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        long N = nums.size() , sum = accumulate(begin(nums), end(nums),0L) ,ans = 0;
        unordered_map<long,long> freqr ,freql;
        for ( long i = 0,l = 0,r=0 ; i <N-1; i++) {
            l += nums[i], r = sum - l;
            freqr[ l - r ]++;
        }
        ans = freqr[0];
      
        for (long i= 0, l =0, r=0; i<N; i++){
            int d = nums[i];            
            long diff  = k - d;
            ans = max(ans, freql[diff] + freqr[-diff]);
            l +=d, r = sum -l;
            freql[l - r]++;
            freqr[l - r]--;            
        }
        return ans;
    }
};