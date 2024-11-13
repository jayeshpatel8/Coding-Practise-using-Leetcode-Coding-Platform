class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(begin(nums),end(nums));
        for (int i1=0;i1<nums.size()-1;i1++ )
        {
            auto i = lower_bound(begin(nums)+i1+1,end(nums),lower-nums[i1]) ;
            auto j = upper_bound(begin(nums)+i1+1,end(nums),upper-nums[i1]);
            
                ans += j-i;
        }
        return ans;
    }
};
