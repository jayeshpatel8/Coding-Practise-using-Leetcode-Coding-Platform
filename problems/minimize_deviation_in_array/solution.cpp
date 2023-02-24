class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // 2 2 5
        priority_queue<int> q;
        int min_ = INT_MAX, ans = INT_MAX;
        for (auto n : nums){
            n = n&1 ? n*2 : n;
            q.push(n);
            min_ = min(min_ , n);
        }
        while (q.top() %2 == 0){
            int n = q.top(); q.pop();
            ans = min(ans, n - min_);
            min_ = min(min_ , n/2);
            q.push(n/2);
        }
        return min(ans,q.top() - min_);
    }
};