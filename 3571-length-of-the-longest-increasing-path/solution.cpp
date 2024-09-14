class Solution {
public:
    int maxPathLength(vector<vector<int>>& co, int k) {
        vector<vector<int>> hi , lo;
        for (auto &c : co){
            if (c[0] > co[k][0] && c[1] > co[k][1]) hi.push_back(c);
            else if ( c[0] < co[k][0] && c[1] < co[k][1]) lo.push_back(c);
        }
        sort(begin(hi),end(hi),[&](auto &a, auto &b){ return a[0] ==b[0]  ?  a[1] > b[1] : a[0] < b[0];});
        sort(begin(lo),end(lo),[&](auto &a, auto &b){ return a[0] ==b[0]  ?  a[1] > b[1] : a[0] < b[0];});
        
        return 1 + LIS(hi) +LIS(lo);
    }
    int LIS( vector<vector<int>> &co) {
        vector<int> ms;
        for(auto c : co){
            auto y = c[1];
            if (auto it = lower_bound(begin(ms), end(ms), y); it == end(ms))
                ms.push_back(y);
            else
                *it = y;      
        }
        return ms.size();
    }
};
