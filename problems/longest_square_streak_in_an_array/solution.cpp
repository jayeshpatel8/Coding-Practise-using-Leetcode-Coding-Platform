class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int f[100001]={};
        for (auto i : nums) f[i]++;
        int ans = -1;
        for (int i=2; i<100001; i++){
            if (f[i]==0) continue;
            int c=1;
            for (size_t j=(size_t)i*i; j<100001; j*=j){
                if (!f[j]) {
                    break;
                }
                f[j]=0;
                c++;
            }
            ans= max(ans,c<2?-1:c);
        }
        return ans;
    }
};