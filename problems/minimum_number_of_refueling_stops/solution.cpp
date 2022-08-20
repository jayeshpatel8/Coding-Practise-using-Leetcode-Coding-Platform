class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& stations) {
        int i=0,ans=  0, N = stations.size(), dist = fuel;
        priority_queue<long> pq;
        
        while (dist < target){           
            while (i<N && stations[i][0] <= dist)
                pq.push(stations[i++][1] );
            
            if (pq.empty()) return  -1;
            dist += pq.top(); pq.pop();
            ans++;
        }
        return ans;
    }
    int minRefuelStops2(int target, int fuel, vector<vector<int>>& stations) {
        if (fuel >= target) return 0;
        int N = stations.size() ;
        vector<long> dist(N+1);
        dist[0] =fuel;
        for (int i=0; i<N; i++){
            for (int j=i; j>=0; j--){
                if (dist[j] >= stations[i][0]){
                    dist[j+1] = max(dist[j+1], dist[j] + stations[i][1]);
                }
            }
        }
        for (int i=0; i<=N; i++){
            if (dist[i] >= target) return i;
        }
        return -1;
    }
};