class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        sort(begin(q),end(q));
        int N=  nums.size(), Nq= q.size(), cnt = 0;
        priority_queue<int> pq;
        vector<int> psum(N+1, 0);

        for (int i=0, j =0; i<N; i++){
            cnt -= psum[i];
            while (j<Nq && q[j][0] <= i){
                pq.push(q[j++][1]);
            }
            while (cnt < nums[i]){
                if (pq.empty() || pq.top() < i) return -1;
                psum[pq.top()+1]++;
                pq.pop(); cnt++;
            }
        }
        return pq.size();
    }
};
