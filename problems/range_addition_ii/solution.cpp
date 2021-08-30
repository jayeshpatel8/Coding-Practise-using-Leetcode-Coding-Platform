class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int r=m,c=n;
        for ( auto &i : ops)
            r = min(r,i[0]), c = min(c,i[1]);
        return r*c;
    }
};