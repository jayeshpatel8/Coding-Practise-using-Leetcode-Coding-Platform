class Solution {
public:
    int minJumps(vector<int>& arr) {
        int  N = arr.size();
        if (N<2) return 0;
        if (arr[0]==arr[N-1]) return 1;
        //BFS
        queue<int>q; q.push(0);
        vector<bool> vis(N);
        unordered_map<int,vector<int>>map;
        for ( int i=0; i<N; i++)
            map[arr[i]].push_back(i);
        int end=N-1,best=N+1,ans=0;
        vis[0]=1;
        while(!q.empty()){
            int sz = q.size();
            while(sz-->0)
            {
                auto i = q.front(); q.pop();

                if (map.count(arr[i])){
                    for (auto j : map[arr[i]]){
                        if (vis[j]) continue;
                        vis[j]=1;
                        q.push(j);
                    }
                    map.erase(arr[i]);
                }
                if (i+1<N && vis[i+1]==0){
                    vis[i+1]=1; q.push(i+1);
                }
                if (i-1>=0 && vis[i-1]==0){
                    vis[i-1]=1; q.push(i-1);
                }                
                if (vis[end]) return ans+1;
            }
            ans++;
        }
        return N;
    }
};