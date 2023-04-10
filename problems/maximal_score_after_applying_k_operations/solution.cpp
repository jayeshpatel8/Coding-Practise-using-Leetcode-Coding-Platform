class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto i : nums) pq.push(i);
        long long ans = 0;
        while (!pq.empty() && k-- > 0){
            auto i = pq.top(); pq.pop();
            ans +=i;
            i = (i/3) + (i%3!=0);
            if (i )
                pq.push(i);
        }
        return ans;
    }
};