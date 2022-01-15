class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int i=1;
        priority_queue<int> pq;
        for (i=1; i<h.size() ; i++)   {
            int diff = h[i] - h[i-1];
            if (diff <=0) continue;
            pq.push(-diff);
            if (pq.size() > ladders){
                auto b = -pq.top(); pq.pop();
                if ( b > bricks) return i-1;
                bricks -=b;
            }
        }
        return i-1;
    }
};