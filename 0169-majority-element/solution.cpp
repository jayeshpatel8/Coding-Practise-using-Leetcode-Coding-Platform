class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =  nums.size();
        unordered_map<int,int> f;
        for (auto i : nums) {
            if (++f[i] > n/2) return i;
        }
        return 0;
    }
};
