class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //  (minutesToTest / minutesToDie) ^ pigs >= buckets
        // pigs >= log (buckets) / log((minutesToTest / minutesToDie))
        return ceil(log2(buckets) / log2(minutesToTest / minutesToDie + 1));
    }
};