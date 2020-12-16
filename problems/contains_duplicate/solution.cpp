class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for (auto i: nums)
            if (m.find(i) != m.end()) return true;
            else m.insert(i);
        return false;
    }
};