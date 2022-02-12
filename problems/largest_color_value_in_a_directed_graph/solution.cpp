class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size(),ans = 0;
        vector<vector<int>> freq(N,vector<int>(26)); 
        vector<int> ed[N], in(N);
        for (auto& e : edges){
            ed[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        queue<int> q;
        for (int i=0; i<N; i++)
            if (in[i]==0)
                q.push(i);
        int vis=0;
        while(!q.empty()){
            int u = q.front(), c = colors[u]-'a';q.pop();
            vis++;
            ans = max(ans, ++freq[u][c]);
            for (auto v : ed[u]){
                for (auto k = 0; k < 26; ++k)
                    freq[v][k] = max(freq[v][k], freq[u][k]);
                if (--in[v] == 0)
                    q.push(v);
            }
        }
        return vis==N? ans : -1;
    }
};