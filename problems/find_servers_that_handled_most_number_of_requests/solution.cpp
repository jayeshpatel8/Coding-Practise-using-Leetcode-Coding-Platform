class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int N  =  arrival.size();
        set<int> free;
        vector<int> cnt(k),ans;
        for (int i=0; i<k; i++) free.insert(i);
        priority_queue<array<long,2>, vector<array<long,2>>, greater<>> pq;        
        for (int i=0; i<N; i++){
            long t =  arrival[i];
            while (!pq.empty() && t>= pq.top()[0] ){
                free.insert(pq.top()[1]);
                pq.pop();
            }
            if (free.empty()) continue;
            auto it =  free.lower_bound(i %k);
            if (it == end(free))
                it =  begin(free);
            auto server = *it;
            pq.push({t+load[i], server});
            cnt[server]++;
            free.erase(server);                        
        }
        int ma =  *max_element(begin(cnt),end(cnt));
        for (auto i=0 ; i<k; i++)
            if (cnt[i]==ma) ans.push_back(i);
        return ans;
    }
};