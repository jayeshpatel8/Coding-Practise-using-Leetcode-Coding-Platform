class Solution {
public:
    
    int mod =  1e9 + 7;
    int countVowelPermutation(int n) {
        
        long a=1,e=1,i=1,o=1,u=1;
        for (int i1=1;i1<n;i1++){
            
            long ta = (e + i + u )%mod;
            long te =(a + i)%mod;
            long ti = (e + o )%mod;
            long to=(i);
            long tu=(i+o)%mod;
            a=ta; e=te; i=ti;o=to;u=tu;
        }
        
        return (a + e + i + o + u) % mod;
    }
};