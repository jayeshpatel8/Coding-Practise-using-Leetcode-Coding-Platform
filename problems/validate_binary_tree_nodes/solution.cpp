class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        vector<int> indeg(n),q;
        for (int i=0; i<n; i++){
            if (lc[i] != -1)
                indeg[lc[i]]++;
            if (rc[i] != -1)
                indeg[rc[i]]++;
        }
        int root=-1;
        for (int i=0; i<n; i++){
            if (indeg[i] ==0 ){
                if (root != -1) return false;
                else root = i;
            }
            else if (indeg[i] > 1) return false;
        }
        if (root == -1)
            return false;
        vector<bool> vis(n);
        
        q.push_back(root);
        while (!q.empty()){
            vector<int> t;
            for (int u : q){
                if (vis[u]) return false;
                if (lc[u] != -1) t.push_back(lc[u]);
                if (rc[u] != -1) t.push_back(rc[u]);
                vis[u]=true;
            }
            q.swap(t);
        }
        return accumulate(begin(vis),end(vis),0)==n;
    }
};