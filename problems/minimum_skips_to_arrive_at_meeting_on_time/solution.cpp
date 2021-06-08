#if 0
class Solution {
public:
    int n, speed;
    //vector<vector<int>> dp; // cur i, use k skips.

    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        n = dist.size();
        //this->speed = speed;
        if ((long)hoursBefore * speed > 1e9)
            return 0;
        if (accumulate(begin(dist), end(dist), 0) > hoursBefore * speed)
            return -1;        
       // dp.resize(n+1, vector<int>(n+1, -1));
        long maxKm=long(speed)*hoursBefore;
       vector<vector<long>> dp(1000, vector<long>(n+1, maxKm));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(j==0)
                {
                    dp[i][j]=0;
                }
                else if(i==0)
                {
                    long prev=dp[i][j-1];
                    if(prev%speed>0)
                    {
                        prev+=(speed-prev%speed);   
                    }
                    dp[i][j]=prev+dist[j-1];
                }
                else
                {
                    long prev=dp[i][j-1];
                    if(prev%speed>0)
                    {
                        prev+=(speed-prev%speed);   
                    }
                    dp[i][j]=min(prev, dp[i-1][j-1])+dist[j-1];
                }
            }
            if(dp[i][n]<=maxKm)
            {
                return i;
            }
        }
        
        return -1;
    }  
};
#else
class Solution {
public:
    int n, speed;
    vector<vector<int>> dp; // cur i, use k skips.

    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        n = dist.size();
        this->speed = speed;
        
        if ((long)hoursBefore * speed > 1e9)
            return 0;
        const long maxDist = speed * hoursBefore;
        if (accumulate(begin(dist), end(dist), 0) > maxDist)
            return -1;        
        dp.resize(n+1, vector<int>(n+1, 0));
        
        for(int k=1; k<=n; k++){
            for (int i=1; i<=n; i++){
                dp[i][k] = (dist[i-1] + dp[i-1][k] + speed - 1) / speed * speed;
                if (k > 1) dp[i][k] =  min(dp[i][k] , dist[i-1] + dp[i-1][k-1] );
            }
            if (dp[n][k] <= maxDist) return k-1;
        }
/*        
        for (int k = 0; k<n; k++){
            if (mSkips(dist,n-1,k) <= speed * hoursBefore){
                printdp(n);
                return k;
            }
        }
        printdp(n);
*/
        return -1;
    }
    void printdp(int n){
        
        for (int i=0; i<n; i++){
            cout << "k = " << i << " : ";
            for (int j=0; j<n; j++){
                cout << dp[j][i] << " ";
            }
            cout << endl;
        }
        return;
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