class Solution {
public:
using pp =  pair<int,int> ;
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<pp> bl,br;
        priority_queue<pp,vector<pp>, greater<>> wl,wr;
        int t=0;
        for (int i=0; i<k; i++)
            bl.push({time[i][0] + time[i][2],  i}) ;
        while (n || !br.empty() || !wr.empty()){

            while (!wr.empty() && wr.top().first <= t){
                auto i =  wr.top().second; wr.pop();
                br.push({time[i][0] + time[i][2],  i});
            }
            while (!wl.empty() && wl.top().first <= t){
                auto i =  wl.top().second; wl.pop();
                bl.push({time[i][0] + time[i][2],  i});
            }  

            if (!br.empty()){
                auto i = br.top().second; br.pop();
                t += time[i][2];
                wl.push({t + time[i][3], i });
            }          
            else if (!bl.empty() && n){
                auto i = bl.top().second; bl.pop();
                t += time[i][0];
                --n;
                wr.push({t + time[i][1], i });
            }      
            else {
                t = !wr.empty()? wr.top().first : INT_MAX;
                t = min<int>(t, !wl.empty() && n ? wl.top().first : INT_MAX);
            }    
        }
        return t;
    }
};