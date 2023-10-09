class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> res(n) ,seen(n), s;
        for (int i = 0, j = 0; i < n; j = ++i) {

            while (!seen[j] && res[j] == 0) {
                seen[j]=1;
                s.push_back(j);
                j = edges[j];
            }
            if ( seen[j]) { // hit the cycle
                
                int k = distance(find(s.begin(), s.end(), j), s.end());
                for (j = 0; j < k; ++j) {
                    res[s.back()] = k;
                    s.pop_back();
                }
            }
            while (!s.empty()) {
                j = s.back();
                s.pop_back();
                res[j] = res[edges[j]] + 1;
            }
        }
        return res;
    }
};