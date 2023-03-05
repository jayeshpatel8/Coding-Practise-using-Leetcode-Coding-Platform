class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int> > map;
        int N = arr.size();
        if  (N<2) return 0;
        vector<int> vis(N);

        for ( int i=0;i< N; i++) map[arr[i]].push_back(i);

        queue<int>   q;
        q.push(0);vis[0]=1;
        int dist = 0;
        while (!q.empty()){
            int sz = q.size();
            while (sz-- > 0){
                
                int i = q.front(); q.pop();
                
                if (i-1 >= 0 && !vis[i-1]){
                    q.push(i-1); vis[i-1]=1;
                }
                if (i+1 < N && !vis[i+1]){
                    q.push(i+1); vis[i+1]=1;
                }
                if (map.count(arr[i])){
                    for (auto j : map[arr[i]]){
                        if (vis[j]) continue;
                        vis[j]=1;
                        q.push(j);
                    }
                    map.erase(arr[i]);
                }
                if (vis[N-1]) return dist+1; 
            }

            dist++;
        }
        return dist;

    }
};