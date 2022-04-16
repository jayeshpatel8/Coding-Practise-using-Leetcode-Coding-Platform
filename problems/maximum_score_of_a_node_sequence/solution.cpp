class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
     int n= scores.size();   
        vector<vector<int>> g(n);
        
        for (auto &e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        for (auto &i : g) partial_sort(begin(i),begin(i)+min<int>(3,i.size()),end(i),[&](auto &a, auto &b){return scores[a]>scores[b];});
        int ans = -1;
        for (auto &e : edges){
            auto u = e[0], v=e[1];
            auto sum = scores[u] +scores[v];
            for (auto u2 : g[u]){
                if (u2==v) continue;
                bool found=0;
                for (auto v2 : g[v]){
                    if (v2!=u2 && v2!=u  ){
                        ans =max(ans, scores[u2] +scores[v2] + sum);
                        found=1;
                        break;
                    }
                    
                }
                if (found)
                    break;
            }
            
        }
        return ans;
    }
};