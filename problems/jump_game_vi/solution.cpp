class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n];
        deque<int> dq;
        dq.push_back(0);
        dp[0]=nums[0];
        for (int i=1; i<nums.size();i++)
        {
            if (dq.front() < i-k) dq.pop_front();
            dp[i] = dp[dq.front()] + nums[i];
            int cur = dp[i];
            while (!dq.empty() && cur > dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[n-1];
    }
};