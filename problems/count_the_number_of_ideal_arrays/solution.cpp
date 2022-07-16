class Solution {
public:
    int comb[10001][14] = { }, cnt[10001][14] = {}, mod = 1e9 + 7;
    const int N= 1e4 + 1;
    
    int idealArrays(int n, int maxValue) {
       
        if (comb[1][1]==0){
            comb[0][0] =1; //ncr[0,0] = 1
            
            for (int div=1; div<N; div++){
               ++cnt[div][0];
                // Sieve of Eratosthenes
                for (int i= 2 * div; i<N; i+=div ){
                    for (int bar = 0; cnt[div][bar]; bar++)
                        cnt[i][bar + 1] +=cnt[div][bar]; //if a number i is divisible by div, it "inherits" all bars of div, adding 1 to each bar.
                    // {1} = 10, {1,2} = 10
                }
            }
            for (int n1= 1; n1<N;n1++)
                for (int r = 0; r <14; r++)
                    comb[n1][r] = r ==0 ? 1 : (comb[n1-1][r]+comb[n1-1][r-1])%mod;
        }
        int ans = 0;
        for (int i=1; i<=maxValue; i++){
           for(int bar=0; bar<min(n,14) && cnt[i][bar];bar++)               
               ans = (ans + (long long)cnt[i][bar] * comb[n-1][bar])%mod;
        }
        
        return ans;
    }

};