class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size()<3) return -1;
        int N = nums.size()-1;
        int a = min({nums[1] , nums[0] , nums[N]});
        int b = max({nums[1] , nums[0] , nums[N]});
        if (nums[0] != a && nums[0] != b ) return nums[0];
        if (nums[1] != a && nums[1] != b ) return nums[1];
        return nums[N];
    }
};