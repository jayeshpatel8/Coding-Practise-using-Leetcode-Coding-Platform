class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<>> pq(begin(nums),end(nums));
        int ans=0;
        while (!pq.empty()){
            auto a  = pq.top(); pq.pop();
            if (a >= k || pq.empty()) return ans;
            auto b  = pq.top(); pq.pop();
 
            pq.push(a * 2LL + b);
            ans++;
        }
        return ans;
    }
};
