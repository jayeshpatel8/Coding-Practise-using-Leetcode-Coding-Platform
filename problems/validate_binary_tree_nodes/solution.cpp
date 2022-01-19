class Solution {
public:
    bool vis[10001]={};
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc){
        int root = -1;
        vector<int> indeg(n);
        for (int i=0; i<n; i++){
            if (lc[i] != -1) indeg[lc[i]]++;
            if (rc[i] != -1) indeg[rc[i]]++;
        }
        for (int i=0; i<n; i++){
            if (indeg[i]==0){
                if (root == -1) root = i;
                else  return false;
            }
        }
        if (root == -1) return false;
        if (! dfs(root,lc, rc)) return false;
        for (int i=0; i<n; i++)
            if (vis[i]==0) return false;
        return true;
    }
    bool dfs(int root, vector<int> &lc , vector<int> & rc){
        if (vis[root]) return false;
        vis[root]=1;
        bool ans = 1;
        if (lc[root] != -1) ans &= dfs(lc[root],lc, rc);
        if (ans && rc[root] != -1) ans &= dfs(rc[root],lc, rc);
        return ans;
    }
    vector<int> parent;
    bool validateBinaryTreeNodes2(int n, vector<int>& lc, vector<int>& rc) {
        vector<int> uf(n, -1);
        parent.resize(n);
        
        for (int i=0; i<n; i++){
            int u  = i;
            if (lc[u] != -1){
               if (!check(uf,i,lc[u])) return false; 
            }  
            if (rc[u] != -1  ){
                if(!check(uf,i,rc[u])) return false;
            }
        }
        
        return count_if(begin(parent),end(parent),[](int i){ return i==0;}) ==1  ;
    }
    int find(vector<int> &uf, int i){
        return  uf[i] == -1 ? i : uf[i] = find (uf, uf[i]);
        
    }
    bool check(vector<int> &uf, int i, int j){
        int p1 =  find (uf,i) , p2 =  find (uf,j);
        if (p2 ==  p1) return false;
        uf[p1]=p2;
        return parent[j]++ < 1;
    }
    void connect (vector<int> & uf, int i, int j){
        int p1 = find (uf, i), p2 =  find (uf , j);
        if (p1 != p2){
            uf[p1] = p2;
        }
    }
};