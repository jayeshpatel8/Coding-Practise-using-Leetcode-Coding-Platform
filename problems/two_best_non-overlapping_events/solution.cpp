class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, pair<int,int>>> pq;
        
        for (auto e : events){
            pq.push({e[0],{0,e[2]}});
            pq.push({e[1],{1,e[2]}});
        }
        int next = 0, ans = 0;
        while(!pq.empty()){
            if (pq.top().second.first) //end
                ans = max(ans, pq.top().second.second + next);            
            else 
                next = max(next, pq.top().second.second);
            
            pq.pop();
        }
        return ans;
    }
};