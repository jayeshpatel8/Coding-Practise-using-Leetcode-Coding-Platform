class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,-1);
        vector<vector<int>> G(n+1);
        for (auto &e : dislikes){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        for (int k=1; k<=n; k++){
            if (color[k] != -1) continue;
            queue<int> q({k});
            bool col=0;
            while (!q.empty()){
                int sz = q.size();
                while (sz-- > 0){
                    int i = q.front();q.pop();
                    if (color[i]==-1) {
                        color[i]=col;
                        for (auto j : G[i]){
                            q.push(j);
                        }
                    }
                    else if (color[i] != col) return false;
                }
                col = !col;
            }
        }
        return true;
    }
};