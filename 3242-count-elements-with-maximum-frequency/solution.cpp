class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int f[101]={};
        for (auto i : nums) f[i]++;
        int m = 0;
        for (auto i : f) m = max(m,i);
        int ans = 0;
        for (auto i : f) if (i==m) ans +=m;
        return ans;

    }
};
