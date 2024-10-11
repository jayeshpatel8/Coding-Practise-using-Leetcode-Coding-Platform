class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int time = times[targetFriend][0];
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> used;
        priority_queue<int, vector<int>,greater<int>> free;
        
        sort(begin(times),end(times), [](auto & a, auto &b)->bool{return a[0] < b[0];});

        int chair =-1;
        for ( auto &t : times ){
            while(!used.empty() && used.top().first <= t[0]){
                free.push(used.top().second);
                used.pop();
            }
            if (t[0] == time) break;            
            
            if (free.empty())  
                used.push({ t[1],++chair});
            else{                
                used.push({ t[1],free.top()}); free.pop();
            }
        }
        return free.empty() ? ++chair: free.top();
    }
};
