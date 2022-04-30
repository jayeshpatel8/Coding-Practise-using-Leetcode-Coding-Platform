class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<array<int,2>> pq;
        int ans = nums[0];pq.push({ans , 0});
        for (int i=1; i < nums.size(); i++){
            int ans1 = nums[i];
            while (!pq.empty() && pq.top()[1] +k <i)
                pq.pop();
            if (!pq.empty())
                ans1 = max(ans1, nums[i] + pq.top()[0]);
            
            ans = max(ans, ans1);
            pq.push({ans1 , i});
        }
        return ans;
    }
};