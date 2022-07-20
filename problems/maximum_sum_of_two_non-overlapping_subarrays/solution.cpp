class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int fLen, int sLen) {
        return max(sum(nums,fLen, sLen), sum(nums,sLen, fLen));
    }
    int sum(vector<int>& nums, int l1, int l2){
        int s1=0,s2=0,N = nums.size();
        vector<int> r(N+1,-1) , l(N+1,-1);
        
        for (int i=0, s=0; i<N; i++){
            s+=nums[i];
            if (i>=l1)
                s -= nums[i-l1];
            l[i+1] = max(s,l[i]);
        }
        int ans = 0;
        for (int i=N-1, s=0; i>=0; i--){
            s+=nums[i];
            if (i<N-l2)
                s -= nums[i+l2];
            r[i] = max(s,r[i+1]);
            ans= max(ans, l[i]+r[i]);
        }
        return ans;
    }
};