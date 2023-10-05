class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
         long sum = accumulate(begin(nums),end(nums),0L),psum=0;
        int N= nums.size(),k = target/sum;
        target %= sum;
        if (target == 0) return k * N;
        
        int ans = N;
        for (int l =0,r=0; r<2*N; r++){
            psum += nums[r%N];
            while (l<=r && psum >target)
                psum -= nums[l++%N];            
            if (psum ==target) ans= min(ans, r-l+1);            
        }
        return ans == N ? -1 : ans + k *N; 
    }
};