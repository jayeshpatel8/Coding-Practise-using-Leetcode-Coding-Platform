class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int f[501]={};
        for (auto &i : nums) f[i]++;
        for (auto &i : f)
            if  (i & 1) return false;
        return true;
    }
};
