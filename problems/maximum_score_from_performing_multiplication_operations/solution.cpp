class Solution {
public:
    int DP[1001];
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int M = mul.size(),N=nums.size();
        for (int i =0; i <= M; i++)
                DP[i]=0;
        for (int m=M-1, diff=N-M; m>=0; m--,diff++){
            for (int i=0; i<N - diff; i++){
                DP[i] = max(DP[i] + nums[i+diff]*mul[m], DP[i+1] + nums[i]*mul[m]);
            }
        }
        return DP[0];
    }
};
#if 0
class Solution {
public:
    int DP[1001][1001];
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        for (int i =0; i < 1001; i++)
            for (int j =0; j < 1001; j++)
                DP[i][j]=-1;
        return ms(0,0,nums,mul);
        
    }
    int ms(int l, int m, vector<int>& nums, vector<int>& mul) {
        if (m>= mul.size()) return 0;
        
        if (DP[l][m]!=-1) return DP[l][m];
        int r = nums.size()-1  +l - m;
        return DP[l][m] = max (
                                nums[l]*mul[m] + ms(l+1,m+1,nums,mul),
                                nums[r]*mul[m] + ms(l,m+1,nums,mul)
                                );
    }
};
#endif