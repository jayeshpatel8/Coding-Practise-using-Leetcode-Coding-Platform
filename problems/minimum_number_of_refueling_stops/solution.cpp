class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& st) {
        int n =  st.size();
        
        st.push_back({target,0});
        int ans=0;
        priority_queue<int> pq;
        int dist = startFuel,i=0;
        //pq.push(startFuel);
        while (dist < target){
            
            while (i < st.size() && st[i][0] <= dist){
                pq.push(st[i][1]); i++;
            }
            if (pq.empty()) return -1;
            dist += pq.top();pq.pop();
            
            ans++;           
        }
    
        return  ans;
    }
};