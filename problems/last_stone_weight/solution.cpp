class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq (begin(stones),end(stones));
        int n = pq.size();
        while (n >  1){
            int v1 = pq.top();pq.pop();
            int v2 = pq.top(); pq.pop();
            if (v1 != v2)
                pq.push(v1-v2),n--;
            else
                n-=2;
        }
        return n ? pq.top() : 0;
    }
};