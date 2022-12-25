class Solution {
public:
    int countAnagrams(string s) {
        int mod = 1e9 +7;
        using ll =long long;
        ll ans = 1;
        ll fact[100005+1];
        fact[0]=1;
        for (int i=1; i<=100005; i++)
            fact[i] = (fact[i-1] * i) % mod;
        auto powMod  = [&](ll n, ll m){ 
            ll ans = 1;
            while (m > 0){
                if (m & 1) ans = (ans *n)%mod;                
                n = (n *n) %mod;
                m>>=1;
            }
            return ans%mod;
        };
        auto invMod  = [&](int n){ return powMod(n,mod-2);};
        s.push_back(' ');
        vector<int> freq(26);
        for (int i=0, j = 0; i<s.size(); i++){
            if (s[i] == ' '){              
                ll perm = fact[i-j];
                for (auto &c : freq){
                    if (c>1)
                        perm =(perm  * invMod(fact[c]) )%mod ;
                    c=0;
                }

                j=i+1;
                ans= (ans * perm) %mod;
            }
            else
                freq[s[i]-'a']++;
        }
        return ans;
    }
    
};