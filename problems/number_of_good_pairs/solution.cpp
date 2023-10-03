class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int f[101]={};
        for (auto i : nums) f[i]++;
        int ans = 0;
        for (int i=1; i<=100; i++)   {
            if (f[i] >1){
                auto n  = f[i]-1;
                ans += (n * (n+1))/2;
            }
        }
        return ans;
    }
};