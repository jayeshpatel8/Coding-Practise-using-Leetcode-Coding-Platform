class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<int> vis(n,false);
        q.push(0);
        vis[0]=true;
        while (!q.empty()){
            int sz = q.size();
            
            for (int i=0; i<sz; i++){
                int u = q.front(); q.pop();                
                for (auto v :rooms[u] ){
                    if(!vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
        }
        for (int i=1; i<n; i++) if (vis[i]==false) return false;
        return true;
    }
};