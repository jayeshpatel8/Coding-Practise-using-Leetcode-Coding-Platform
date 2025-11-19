class Solution {
public:
    int findFinalValue(vector<int>& nums, int org) {
        int f[1001]={};
        for (auto i : nums) f[i]=1;
        while (org <1001 && f[org])
            org *=2;
        return org;
    }
};
