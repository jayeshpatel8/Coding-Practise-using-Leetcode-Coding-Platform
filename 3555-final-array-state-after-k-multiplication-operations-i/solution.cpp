class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        using pi = pair<int, int>;
        priority_queue<pi, vector<pi> , greater<>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        while (k--) {
            auto [value, i] = pq.top(); pq.pop();
            nums[i] *= multiplier;
            pq.push({nums[i], i});            
        }

        return nums;
    }
};
