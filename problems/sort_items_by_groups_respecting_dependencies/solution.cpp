class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)     {
        for (auto &i : group)        
            if (i == -1) i=m++;
        vector<vector<int>> graphGroup(m), graphItem(n);
        vector<int> inGroup(m), inItem(n);
        for (int i=0; i<n;  i++){
            int to = group[i];
            for (auto j : beforeItems[i]){
                int from = group[j];
                if (from != to){
                    graphGroup[from].push_back(to);
                    inGroup[to]++;
                }
                graphItem[j].push_back(i);
                inItem[i]++;
            }
        }
        
        vector<int> gr_topo_sorted = toposort(graphGroup,inGroup);
        if (gr_topo_sorted.size()<m) return {};
        vector<int> item_topo_sorted = toposort(graphItem,inItem);
        if (item_topo_sorted.size()<n) return {};
        
        vector<vector<int>>gr_to_item(m);
        for (auto i : item_topo_sorted){
            gr_to_item[group[i]].push_back(i);
        }
        vector<int> ans;
        for ( auto g : gr_topo_sorted){
            for (auto i : gr_to_item[g])
                ans.push_back(i);
        }
        return ans;
    }
    vector<int> toposort(vector<vector<int>>& g, vector<int>& in){
        queue<int> q;
        for (int i=0; i<in.size(); i++){
            if (in[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int i = q.front(); q.pop();
            ans.push_back(i);
            for (auto j : g[i]){
                if (--in[j] == 0)
                    q.push(j);                               
            }
        }
        return ans;
    }
};