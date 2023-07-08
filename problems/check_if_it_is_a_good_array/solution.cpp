class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int ans = nums[0];
        for (auto i : nums) 
            ans = gcd (ans, i);
        return ans == 1;
    }
};