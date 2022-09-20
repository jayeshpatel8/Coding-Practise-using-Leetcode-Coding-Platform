class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& M) {
        sort(begin(M),end(M));
        set<int> free;
        int f[101]={};
        priority_queue<array<long,2>,vector<array<long,2>>,greater<>> pq;
        for (int i =0; i<n; i++) free.insert(i);
        for (auto &m : M){
            while (!pq.empty() && m[0] >= pq.top()[0]) {
                free.insert(pq.top()[1]);
                pq.pop();
            }
            if (!free.empty()){
                auto it = begin(free);
                pq.push({ m[0] + m[1] - m[0],*it});
                f[*it]++;
                free.erase(it);
                
            }
            else{
                auto room = pq.top()[1];
                f[room]++;
                pq.push({ pq.top()[0] + m[1] - m[0],room});
                pq.pop();
            }
        }
        int time=-1, ans=0;
        for (auto i=0; i<=n; i++){
            if (time <f[i]){
                time=f[i];
                ans= i;
            }
        }
        return ans;
    }
};