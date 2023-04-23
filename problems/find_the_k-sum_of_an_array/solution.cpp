class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long m_sum = 0;
        for (auto &i : nums){
            if (i >= 0) m_sum += i;
            else i = abs(i);
        }
        sort(begin(nums),end(nums));
        priority_queue<pair<long long , int>> pq;
        pq.push({m_sum - nums[0],0});
        long long ans= m_sum;
        while (--k){
            auto [sum, i] = pq.top(); pq.pop();
            ans =  sum;
            if (i+1<nums.size()){
                sum -= nums[i+1];
                pq.push({sum , i+1});
                pq.push({sum +  nums[i] , i+1});

            }
        }
        return ans;
    }
};