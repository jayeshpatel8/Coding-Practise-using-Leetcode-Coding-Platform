class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        unordered_map<int,multiset<int,greater<int>>> nodes;
        int ans= INT_MIN;
        //for (auto v : vals)
        //    ans= max(ans, v);
        //if (k<=0) return ans;
        for (auto &e : edges){
            int u = e[0] , v = e[1];
            if (vals[v]>0)
                nodes[u].insert(vals[v]);
            if (vals[u]>0)
                nodes[v].insert(vals[u]);            
        }
        
        for (int n=0;n<vals.size(); n++){
            int cnt=k , sum = vals[n];
            
            if (cnt > 0){
                for (auto e: nodes[n]){
                    if (cnt-- <= 0 || e <= 0) break;
                    sum += e;
                }
            }
            ans= max(ans, sum);
        }
        return ans;
    }
};