class Solution {
public:
    int N,dp[12][1<<12];
    
    int numSquarefulPerms(vector<int>& nums) {
        N= nums.size();        
        memset(dp,-1,sizeof(dp));

        return count(nums,0,0);
    }
    bool issquare(int a){
        int n = sqrt(a);
        return (n*n==a);
    }
    int count(vector<int>& nums,int idx, int mask) {
        if (mask == (1<<N)-1){ return 1;}
        if (dp[idx][mask] != -1) return dp[idx][mask];
        int ans = 0;
        unordered_set<int> rep;
        for(int i=0; i<N; i++){
            if( rep.count(nums[i])) continue;
            if (mask ==0 || (((mask & 1<<i) == 0)  && issquare(nums[i]+nums[idx]))){
                rep.insert(nums[i]);
                ans += count(nums,i,mask | (1<<i));
            }
        }
        return dp[idx][mask] = ans;
    }
};

