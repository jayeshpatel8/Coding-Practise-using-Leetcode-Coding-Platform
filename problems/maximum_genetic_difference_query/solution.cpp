class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> M;
    vector<int> res;
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& que) {
        vector<vector<int>> g(parents.size());
        int root;
        for (int i=0; i<parents.size(); i++){
            if (parents[i]==-1) root=i;
            else
                g[parents[i]].push_back(i);
        }
        
        for (int i=0; i<que.size(); i++) M[que[i][0]].push_back({i,que[i][1]});
        res.resize(que.size());
        dfs(g, root);
        return res;
    }

    struct Trie{
        Trie * bit[2] ={};
        int cnt=0;
        void insert(int node,int pos=17){
            cnt++;
            if (pos < 0) return;
            int b= (node  >> pos) & 1;
            if (bit[b] == NULL)
                bit[b] = new Trie();
            bit[b]->insert(node , pos-1);
        }
        void remove(int node, int pos=17){
            cnt--;
            if (pos < 0) return;
            int b= (node  >> pos) & 1;
            bit[b]->remove(node , pos-1);
        }
        int diff(int val, int pos=17){
            if (pos < 0) return 0;
            int b= (val  >> pos) & 1;
            if (bit[!b] && bit[!b]->cnt > 0) return (1 << pos) + bit[!b]->diff(val, pos-1);
            else 
                return bit[b] ? bit[b]->diff(val, pos-1) : 0;
        }
    };
    Trie trie;
    void dfs(vector<vector<int>> & g, int i){
        trie.insert(i);
        for (auto &[idx,val] : M[i]) 
            res[idx] = trie.diff(val);
        for (auto &v : g[i]) 
            dfs(g,v);
        trie.remove(i);
    }    
};