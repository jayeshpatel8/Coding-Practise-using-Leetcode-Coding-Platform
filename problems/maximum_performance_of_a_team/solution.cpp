class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> A;
        for (int i=0; i<speed.size(); i++)
            A.push_back({efficiency[i],speed[i]});
        sort(rbegin(A),rend(A));
        priority_queue<int> pq;
        long sum=0, ans = 0;
        int mod = 1e9 +7;
        for (auto &[e,s] : A){
            sum+=s;
            pq.push(-s);
            if (pq.size() > k){
                sum+=pq.top(); pq.pop();
            }
            ans = max(ans, sum * e );
        }
        return ans % mod;
    }
};