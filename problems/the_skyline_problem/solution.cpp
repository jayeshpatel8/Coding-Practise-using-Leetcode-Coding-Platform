class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<array<int,2>> pq; pq.push({0,INT_MAX}); // height, end_distance
        set<array<int,3>> event; // start/end distance, 0-start/1-end, index i
        for (int i=0;i<  buildings.size(); i++) {
            event.insert({buildings[i][0],0,i}); event.insert({buildings[i][1],1,i});
        }
        vector<vector<int>> ans; 
        ans.push_back({(*event.begin())[0],(*event.begin())[2]});
        
        for ( auto &i : event){
            if (i[1] == 0) // start
                pq.push({buildings[i[2]][2],buildings[i[2]][1]});
            else{ // end
                while(!pq.empty() && pq.top()[1] <= i[0]) // remove till cur end distance
                    pq.pop();
            }
             if ( ans.back()[1] != pq.top()[0]){ // ignore no change in height
                if (ans.back()[0]== i[0]){ // multiple end distance
                    ans.back()[1] = pq.top()[0]; //only update height
                }
                else
                    ans.push_back({i[0],pq.top()[0]});
            }
        }
        return ans;
    }
};