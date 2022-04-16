class Solution {
public:
    int findClosestNumber(vector<int>& nums) {        
        int ans = INT_MAX;
        for (auto i : nums)
        {
            if (abs(ans) > abs(i) || abs(ans) == abs(i) && i > ans)
                ans = i;
        }
        return ans;
    }
};