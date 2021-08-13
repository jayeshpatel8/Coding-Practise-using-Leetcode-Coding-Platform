class Solution {
public:
    int N;
    int dp[1001][51];
    int splitArray(vector<int>& nums, int M) {
         N= nums.size();
        if(N==M) return * max_element(begin(nums),end(nums));
        
        int l=0, r = accumulate(begin(nums), end(nums),0);
        while(l<=r){
            int mid = l+(r-l)/2;
            if (partation(nums,M,mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
        
        vector<int> psum(N+1);
        for (int i=0; i<N; i++) psum[i+1] = psum[i] + nums[i];
        
        
        
        // memo
        //memset(dp,-1,sizeof(dp));
        //return lsum(nums, 0,M,psum);

        for(int i=0; i<N; i++) dp[i][1] = psum[N]-psum[i];
        for (int m=2; m<=M; m++){            
            for(int i=0; i<=N-m; i++){
                dp[i][m]=INT_MAX;        
                for(int j=i; j<=N-m; j++)                                   
                    dp[i][m] = min(dp[i][m], max(psum[j+1]-psum[i], dp[j+1][m-1]));
            }
        }
        return dp[0][M];
        
    }
    bool partation(vector<int>& nums, int m, int mid){
        int i=0;
        while (m > 0 ){
            int sum = 0;
            while (i < nums.size() && sum + nums[i] <= mid) 
                sum += nums[i++];
            --m;
        }
        return (i == nums.size());
    }
    int lsum(vector<int>& nums, int i, int m , vector<int> &psum){
        if(i>=N || m<=0) return 0;
        if ( m == 1) return psum[N] - psum[i];
        
        if (dp[i][m] != -1) return dp[i][m];
        int ans  = INT_MAX;
        for (int  j = i; j<N-m; j++)
            ans = min(ans , max(psum[j+1]-psum[i] , lsum (nums, j+1,m-1,psum)));
        return dp[i][m] = ans;
        
    }
    
};