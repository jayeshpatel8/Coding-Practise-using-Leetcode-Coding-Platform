class Solution {
public:
    int minJumps(vector<int>& arr) {
      int n = arr.size();
        vector<bool> vis(n);
        unordered_map<int,vector<int>> map;
        for (int i=0; i<n; i++) {
            if (i==0 || i==n-1|| !(arr[i-1] ==arr[i] && arr[i] ==arr[i+1]) )
            map[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0); vis[0]=1;
        int step=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz-- > 0){
                int u = q.front(); q.pop();
                if (u == n-1) return step;
                if (u>0 && !vis[u-1] ) q.push(u-1),vis[u-1]=1;
                if (!vis[u+1] ) q.push(u+1),vis[u+1]=1;
                for (auto v : map[arr[u]]){
                    if (u!= v && !vis[v])
                        q.push(v),vis[v]=1;
                }
                map[arr[u]].clear();
            }
            step++;
        }
        return 0;
    }
};