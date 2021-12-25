class Solution {
public:
    int minWastedSpace(vector<int>& pack, vector<vector<int>>& boxes) {
        sort(begin(pack), end(pack));
        long pack_sum = accumulate(begin(pack), end(pack),0L), ans = LONG_MAX;
        int mod = 1e9 + 7, max_pack = pack.back();
        
        for( auto &box : boxes){
            sort(begin(box), end(box));
            if (box.back() < max_pack) continue;
            long total=0;
            auto prev = 0;
            for (auto &b : box){
                auto cur  = upper_bound(begin(pack), end(pack), b) -begin(pack);
                total += b  * (cur - prev);
                prev = cur;
            }
            ans = min (ans, total - pack_sum);
        }
        return (ans == LONG_MAX) ? -1 : (ans % mod);
    }
};