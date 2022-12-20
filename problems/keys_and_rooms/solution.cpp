class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        vis[0]=true;
        queue<int> q;
        q.push(0);
        while (!q.empty()){
            int j = q.front();
            q.pop();
            for (auto i : rooms[j]){
                if (vis[i]) continue;
                vis[i]=true;
                q.push(i);
            }
        }
        return accumulate(begin(vis),end(vis),0) == n;
    }
};