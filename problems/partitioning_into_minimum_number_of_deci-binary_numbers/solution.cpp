class Solution {
public:
    int minPartitions(string n) {
        char ans = '0';
        for (auto i : n)
            ans = max(ans, i);
        return ans-'0';
    }
};