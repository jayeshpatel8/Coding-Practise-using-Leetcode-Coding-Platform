class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        if (!p) return 0;
        sort(begin(nums), end(nums));
        int l=0, r=nums.back(), N = nums.size();
        while (l<r){
            int m = l + (r-l)/2, cnt =  p;
            for (int i=1; cnt> 0 && i<N; i++){
                if (nums[i] - nums[i-1] <= m) i++,--cnt;
            }
            if (cnt<=0) r=m;
            else l=m+1;
        }
        return r;
    }
};
