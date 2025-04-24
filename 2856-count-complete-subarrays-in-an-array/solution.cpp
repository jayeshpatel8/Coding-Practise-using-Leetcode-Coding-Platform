class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int N  = nums.size(),ans=0;
        vector<int> dp(N),cnt(2001);
        set<int> dist(begin(nums),end(nums));
        int dn =  dist.size();
        if (dn==1) return (N * (N+1))/2;
        for (int i=0,j=0,d=0; i<N; i++){
            if (cnt[nums[i]]++ == 0) d++;
            while (d >= dn){
                if (--cnt[nums[j++]]==0) d--;
                ans += N-i;
            }
        }
        return ans;
    }
};
