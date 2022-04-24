class Solution {
public:
    int countLatticePoints(vector<vector<int>>& cir) {
        int n  = cir.size();
        set<pair<int,int>> cnt;
        for (auto &c : cir){
            int x = c[0], y = c[1], r = c[2];
            for (int i = -r; i <= r; i++) {
                for (int j = -r; j <= r; j++) {
                    if (i * i + j * j <= r * r) {
                        cnt.insert({i + x, j + y});
                    }
                }
            }
        }
        return cnt.size();
    }
};