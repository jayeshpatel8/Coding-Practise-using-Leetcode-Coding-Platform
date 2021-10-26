class Solution {
public:
    vector<long long> dp;
    int countHighestScoreNodes(vector<int>& parents) {
        vector<vector<int>> child(parents.size());
        for (int c=1; c<parents.size(); c++){
            child[parents[c]].push_back(c);
        }
        dfs(child,0);
        return count(begin(dp), end(dp), *max_element(begin(dp), end(dp)));
    }
    int dfs(vector<vector<int>>& child, int i){
        long long total= 1, prod = 1;
        for ( auto c : child[i]){
            size_t cnt= dfs(child, c);
            prod *= cnt;
            total += cnt;
        }
        dp.push_back( prod * max(1ULL, child.size() - total));
        return total;
    }
};