class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N=  colors.size();
        vector<int> deg(N);
        vector<vector<int>> G(N);
        queue<int> q;
        for (auto & e : edges)
            G[e[0]].push_back(e[1]), deg[e[1]]++;

        for (int i=0; i<N; i++){            
            if (!deg[i])
                q.push(i); 
        }
        vector<vector<int>> freq(N,vector<int>(26));
        int visited=0, ans = 0;
        while (!q.empty()){
            visited++;
            int u = q.front(); q.pop();
            freq[u][colors[u]-'a']++;
            ans=  max(ans, freq[u][colors[u]-'a']);

            for (auto v : G[u]){
                for (int i=0; i<26; i++)
                    freq[v][i] = max(freq[v][i], freq[u][i]);
                if (deg[v]-- == 1) {
                    q.push(v);
                }
            }
        }
        return visited==N ? ans : -1;
    }
};
