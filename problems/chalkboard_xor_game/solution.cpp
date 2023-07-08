class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for (auto i : nums) x ^= i;
        return (x==0 || 0==(nums.size() & 1));
    }
};