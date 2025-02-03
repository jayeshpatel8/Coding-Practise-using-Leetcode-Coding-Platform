class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec=1, ans = 1;
        for (auto i=1; i<nums.size(); i++){
            if (nums[i]  < nums[i-1]) dec++,inc=1;
            else if (nums[i] > nums[i-1]) inc++,dec=1;
            else inc=dec=1;
            ans = max({ans,inc,dec});
        }
        return ans;
    }
};
