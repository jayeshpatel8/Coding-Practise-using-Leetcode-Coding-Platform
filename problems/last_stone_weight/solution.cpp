class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq (begin(stones), end(stones));
        while (!pq.empty()){
            int a = pq.top(); pq.pop();
            if (pq.empty()) return a;
            int b = pq.top(); pq.pop();
            if (a!=b)
                pq.push(a-b);
        }
        
        return 0;

    }
};