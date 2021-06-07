#if 1
class Solution {
public:
    int n, speed;
    vector<vector<int>> dp; // cur i, use k skips.

    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        n = dist.size();
        this->speed = speed;
        if ((long)hoursBefore * speed > 1e9)
            return 0;
        if (accumulate(begin(dist), end(dist), 0) > hoursBefore * speed)
            return -1;        
        dp.resize(n+1, vector<int>(n+1, -1));
       
        for(int k = 0; k <= n; ++k){
            if(mSkips(dist,n-2, k) <=1LL * hoursBefore * speed - dist.back())
                return k;
        }
        
        return -1;
    }
    int mSkips( vector<int>& arr, int i, int k){
        if (i < 0 ) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        
        int res = (mSkips(arr,i-1, k) + arr[i] + speed - 1) / speed * speed; 
        if (k > 0) res = min(res, mSkips(arr,i-1,k-1)+ arr[i] );
        
        return dp[i][k]=(res);;
    }
   
};

#endif