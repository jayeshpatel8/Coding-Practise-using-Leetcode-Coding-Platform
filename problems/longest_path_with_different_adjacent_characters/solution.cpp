class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n =  parent.size();
        vector<vector<int>> len(n,vector<int>(2)); // 2 highest length to save
        vector<int> child_cnt(n);
        for (auto i = 1; i<n; i++ ) child_cnt[parent[i]]++;
        queue<int> q;
        for (int  i=1; i<n; i++ )  if (child_cnt[i] == 0) q.push(i);
        while (!q.empty()){
            int v = q.front(); q.pop();
            int u = parent[v];
            if (u >= 0){
                if ( s[u]!=s[v]){
                    int l = len[v][0] + 1;
                    if (len[u][0] < l) 
                        len[u][1] = len[u][0], len[u][0]= l;
                    else if (len[u][1] < l)
                        len[u][1] = l;
                }
                if (--child_cnt[u] == 0)
                    q.push(u);
            }
        }
        int ans = 0;
        for (auto &i : len)
            ans=  max(ans, i[0]+i[1]);
        return ans + 1;
    }
};