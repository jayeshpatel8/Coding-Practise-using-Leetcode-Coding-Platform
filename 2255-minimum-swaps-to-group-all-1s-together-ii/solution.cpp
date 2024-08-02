class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int cnt = 0;
        for (auto  i : nums) cnt+=i;
        if ( cnt==0 || nums.size() == cnt) return 0;
        int ones=0;
        for (int i=0; i < cnt; i++) ones += nums[i];
        int ans = cnt - ones;
        for (int i=0, j=cnt; i<nums.size(); i++, j = (1+j)%nums.size()){
            ones += nums[j] - nums[i] ;
            ans = min(ans, cnt - ones);
        }

        return ans;
    }
};
