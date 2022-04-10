class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,greater<long>> pq(begin(nums),end(nums));
        while(k-->0){
             auto t = pq.top(); pq.pop();
            pq.push(++t);
        }
        int mod = 1e9 + 7, ans = 1;
        while (!pq.empty()){
            ans =  (ans * pq.top())%mod;
            pq.pop();
        }
        return ans;
    }
};