class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<array<int,2>> q;
        q.push_back({headID,informTime[headID]});
        vector<vector<int>> G(n);
        for (auto i =0; i<n; i++) if (i != headID) G[manager[i]].push_back(i);

        int ans = INT_MIN;
        while (!q.empty()){
            vector<array<int,2>> t;
            for (auto & [u,ti] : q){
                ans= max(ans, ti);
                for (auto v : G[u])
                    t.push_back({v,ti+informTime[v]});
            }
            q.swap(t);
        }
        return ans;
    }
};