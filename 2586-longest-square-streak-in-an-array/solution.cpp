class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int f[100001]={};
        for (auto i : nums) f[i]=1;

        int ans = 0;
        for (unsigned long i=2; i < 100001; i++){
            if (!f[i]) continue;
            int cnt=0;
            for (unsigned long j=i*i; j<100001 && f[j]; j*=j) cnt++,f[j]=0;
            if (cnt > ans) ans = cnt; 
        }
        return ans == 0 ? -1 : ans + 1;
    }
};
