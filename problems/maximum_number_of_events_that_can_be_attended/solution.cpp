class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort (begin(events), end(events));
        priority_queue<int,vector<int>,greater<int>> pq;
        int N = events.size(), ans = 0, i=0;
        for (int d= events[0][0]; !pq.empty() || i<N ; d++){
            while(!pq.empty() && pq.top() < d) pq.pop();
            while(i<N && events[i][0]  == d) pq.push(events[i++][1]);

            if (!pq.empty())
                pq.pop(), ans++;
        }

        return ans;
    }
};