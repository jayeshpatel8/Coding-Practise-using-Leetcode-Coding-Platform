class Solution {
    //int dp[1000];
    unordered_map<int,long> dp;
    const int MOD = (int)1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        // [2,4,5,10]
        //20 => 2 10, 4 5  
        

        sort(arr.begin(), arr.end());

        for (int i=0; i< arr.size(); i++) {dp[arr[i]]=1;}
        
        
        long ans=0;
        for (int i=0;  i < arr.size(); i++){              
            long cnt=0;
            for (int j=0; j<i; j++){
                int a =  arr[i] % arr[j];
                if ( a == 0){
                    int  b = arr[i] / arr[j];
                     if (dp.count(b) ){                     
                        cnt = (cnt +  dp[arr[j]]* dp[b])%MOD; 
                     }
                }
            }
            dp[arr[i]]+=cnt;            
            ans +=dp[arr[i]];
            
        }       
        return ans%MOD;
    }

};