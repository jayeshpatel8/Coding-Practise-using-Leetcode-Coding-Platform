class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        vector<long> freq(101);
        for (auto i : arr) freq[i]++;
        int ans = 0, mod = 1e9 + 7;

        for (int i=0; i<=100; i++){
            if (freq[i] ){
                if (freq[i] >1){
                    long long next = target - (2 * i);
                    if (next != i && next>=0 && next <=100){
                        if (freq[next]){
                            ans = ( ans  + (freq[i]-1) * freq[i]/2  * freq[next])%mod;
                        }
                    }
                }
                if (freq[i] >2){
                    long long next = target - 3 * i;
                    if (next==0){                        
                        ans = ( ans  + (freq[i]-2) * (freq[i]-1) * (freq[i])/6)%mod;                   
                    }                    
                }
                //>0
                {
                    for (int j=i+1; j<101; j++){
                        long long next = target - i -j;    
                        if (next > j && next <=100){
                            ans = ( ans  + freq[i] * (freq[j]) * (freq[next]))%mod;          
                        }
                    }                                        
                }
            }
        }
        return ans;
    }
};