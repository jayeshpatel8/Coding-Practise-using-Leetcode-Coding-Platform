class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cur = 0;
        for (auto i : nums)
            if (i) cur++;
            else
                ans = max(ans,cur), cur = 0;
        return max(ans,cur);
    }
};