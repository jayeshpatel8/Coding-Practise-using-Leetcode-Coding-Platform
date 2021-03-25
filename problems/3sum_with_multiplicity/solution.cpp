class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long freq[101]={};
        
        for(auto  i: arr) freq[i]++;
        
        int num[101],n=0,mod = (int)1e9 + 7;
        uint64_t ans=0;
        for(int i=0; i<101; i++){
            if(freq[i]) num[n++]=i;
        }
        
        for (int i=0; i<n; i++){
            int a = num[i];
            int diff  = target - a;
            int j=i,k=n-1;
            while(j<=k){
                int b = num[j], c = num[k];
                if(b + c < diff) j++;
                else if (b+c > diff) k--;
                else {
                    if (i< j && j < k ) 
                        ans += freq[a] * freq[b] * freq[c];
                    else if ((i<j && j == k ) || (i==j && j < k ))                        
                        ans += freq[a] * (freq[b]-1) * freq[c]/2 ; 
                    else  
                        ans += freq[a] * (freq[b]-1) * (freq[c]-2)/6;
                    j++,k--;
                    ans %=mod;
                    
                }                
            }
        }
        return ans;
    }
};