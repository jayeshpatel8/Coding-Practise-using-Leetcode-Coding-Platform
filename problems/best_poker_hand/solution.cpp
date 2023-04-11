class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int,int> r;
        unordered_map<char,int> f;
        for (auto c : suits) f[c]++;
        for (auto i : ranks) r[i]++;
        for (auto [k ,i] : f) if (i>=5) return "Flush";
        for (auto [ k,i] : r) if (i>=3) return "Three of a Kind";
        for (auto [ k,i] : r) if (i>=2) return "Pair";
        return "High Card";
    }
};