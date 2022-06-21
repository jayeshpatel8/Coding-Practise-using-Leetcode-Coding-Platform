class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<>> pq;
       
        for (int i = 1; i< heights.size(); i++){
            if (heights[i] <= heights[i-1]) continue;
            int diff = heights[i] - heights[i-1];
            if (ladders > 0){
                ladders--;
                pq.push(diff);
            }
            else{                
                pq.push(diff);
                bricks -= pq.top();
                pq.pop();
                if (bricks < 0) return i-1;
            }
        }

        return heights.size()-1;
    }
};