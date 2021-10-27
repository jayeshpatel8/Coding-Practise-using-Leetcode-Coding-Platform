class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }

    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for (int i=0; i<k-1; i++) pq.push({nums[i],i});
        
        for (int i=k-1, j = 0; i < nums.size(); i++){
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);
            while(!pq.empty() && pq.top().second <= j) pq.pop();
            j++;
        }
        return ans;
    }
};