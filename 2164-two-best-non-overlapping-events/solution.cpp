class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>> pq;
        sort(begin(events),end(events));
        int max_ = 0, ans = 0;
        for (auto e : events){
            
            while(!pq.empty() && (-pq.top().first < e[0]) ){
                max_ = max(max_ , pq.top().second);
                pq.pop();
            }
            ans = max(ans, max_+ e[2]);
            pq.push({-e[1],e[2]});
        }
        return ans;
    }
};
