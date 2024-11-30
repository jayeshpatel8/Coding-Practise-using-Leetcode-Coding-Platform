class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> inout;
        for (auto &i: pairs){
            g[i[0]].push_back(i[1]);
            inout[i[0]]++;
            inout[i[1]]--;
        }
        auto head = find_if(begin(inout), end(inout), [&](auto &p){ return p.second > 0;});
        vector<int> stack{head != end(inout) ? head->first:pairs[0][0]}, path;
        while(!stack.empty()){ //DFS
            int u = stack.back();
            while(!g[u].empty()){
                int v = g[u].back();
                stack.push_back(v);
                g[u].pop_back();
                u = v;
            }
            path.push_back(u);
            stack.pop_back();
        }
        vector<vector<int>> ans;
        for (int i=path.size()-1; i>0; i--){
            ans.push_back({path[i],path[i-1]});
        }
        return ans;
    }
};
