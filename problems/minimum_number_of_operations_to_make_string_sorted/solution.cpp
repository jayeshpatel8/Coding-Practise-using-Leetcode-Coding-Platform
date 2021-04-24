class Solution {
public:
    const int mod = (int)1e9 + 7;
    
    long invmod(long a, long b, long m){
        
        long ans = 1;
        while(b > 0){
            if(b & 1){
                b--;
                ans = (ans * a) % m;
            }
            b >>=1;
            a =   (a * a) % m;
        }
        return ans;
    }
    int makeStringSorted(string s) {        
        int n=s.length();
        long rep[26]={};
        for (auto c : s)
            rep[c -'a']++;
        
        long fact[n+1];
         long iv[n+1];
        fact[0]=1;
        for (int i=1; i<=n; i++) {
            fact[i] = (i * fact[i-1]) % mod;
            iv[i] = invmod(fact[i], mod-2, mod);
        }
        long ans=0;
        for (int i=0; i < n; i++){
            int curr = s[i]-'a';
            
            long smaller=0, div=1;
            for (int k=0; k <26; k++){
                if (k<curr)// find all smaller than s[i]
                    smaller +=rep[k];
                if (rep[k]>1) // all repeated on right
                    div = (div * iv[rep[k]]) % mod;                 
            }
            
            ans =  (ans + (((smaller * fact[n - i  - 1]) % mod ) * (div) ) % mod ) % mod;
            rep[curr]--; // remove left
        }
        return ans;
    }
};