class Solution {
public:
    typedef pair<long, long> pi;
    class compare1{
      public:
        bool operator() (pi &a , pi &b) {
            return (a.first == b.first ) ? a.second > b.second : a.first > b.first ;
        }
    };
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // free sorted on w then index
        // busy keep track when to add to free at each second
        priority_queue<pi, vector<pi>, compare1> free;
        priority_queue<pi, vector<pi>, greater<pi>> busy;
        int n = tasks.size();
        vector<int> ans(n);
        // [3,3,2]
        // [1,2,3,2,1,2]
        //
        for (int i=0; i< servers.size(); i++) free.push({ servers[i],i });
        for (long  j  =0 ,t=0; j<n; j++ ){
            
            t = max(t,j);
            if (free.empty()) t = busy.top().first;
            
            while(!busy.empty() && t >= busy.top().first ){
                
                int idx = busy.top().second;
                
                free.push({ servers[idx],idx });
                busy.pop();
            }            
            int idx = free.top().second;free.pop();
            
            ans[j] = idx;
               
            busy.push({t + tasks[j] ,idx });
        }
        return ans;
    }
    vector<int> assignTasks2(vector<int>& servers, vector<int>& tasks) {
    priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> avail, busy;
    vector<int> res;
    for (int i = 0; i < servers.size(); ++i)
        avail.push({ 0, servers[i], i });
    for (long t = 0; t < tasks.size(); ++t) {
        while(!busy.empty() && (busy.top()[0] <= t || avail.empty())) {
            auto [time, w, i] = busy.top(); busy.pop();
            avail.push({ time <= t ? 0 : time, w, i });
        }
        auto [time, w, s] = avail.top(); avail.pop();
        busy.push({ max(time, t) + tasks[t], w, s });
        res.push_back(s);
    }
    return res;
}
};

