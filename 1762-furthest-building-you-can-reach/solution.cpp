class Solution {
public:
    int furthestBuilding(vector<int>& he, int br, int la) {        
        priority_queue<int,vector<int>, greater<>> pq;
        int ans=0;
        for (int i=1; i<he.size(); i++){
            auto diff = he[i] -he[i-1];
            if (diff <= 0) continue;
            pq.push(diff);
            if (la){
                la--;                
            }
            else{
                auto t = pq.top();pq.pop();
                br -= t;
                if (br < 0) return i-1;

            }            
        }
        return he.size()-1;
    }
};
