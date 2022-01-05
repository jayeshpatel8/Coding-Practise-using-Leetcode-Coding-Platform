class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int ans = 0, ans2=0, n = fav.size();
        vector<bool> vis(fav.size());
        vector<int> in(n) ,dist(n);
        queue<int> q;
        for (int i=0; i<n; i++){
            //in[i]++;
            in[fav[i]]++;
        }
        for (int i=0; i<n; i++)
            if (in[i] == 0)
                q.push(i);
        while(!q.empty()){
            int u = q.front() , v = fav[u]; q.pop();
            dist[v] = max(dist[v], dist[u]+1);
            vis[u]=1;
            if (--in[v] == 0) q.push(v);            
        }
        for (int i=0; i<n; i++){
            if (vis[i]==0){
                // find len of circle
                int len=0;
                for (int j = i; !vis[j] ; j=fav[j]){
                    vis[j]=1; ++len;
                }
                if (len==2){ // 2 + len of both arm
                    ans2 += 2 + dist[i] +dist[fav[i]];
                }
                else
                    ans = max(ans,len);
            }
        }
        return max(ans,ans2);
    }
  
};