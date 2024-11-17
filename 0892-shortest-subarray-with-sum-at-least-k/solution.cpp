class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = INT_MAX;
        deque<int> dq;
        vector<long> psum(nums.size());
        for (int i=0; i<nums.size(); i++){
            psum[i]= nums[i];
            if (i > 0){
                psum[i] += psum[i-1];
            }
            if (psum[i] >= k) ans = min(ans, i+1);
            while (!dq.empty() && (psum[i] - psum[dq.front()] >=k)){
                ans = min ( ans, i- dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && psum[dq.back()] > psum[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
