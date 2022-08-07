class Solution {
public:
    int countVowelPermutation(int n) {
        long cnt[126]={} , mod  = 1e9 + 7;
        for ( auto c : string("aeiou"))
            cnt[c]=1;
        for (int j=1;j<n;j++){
            int e =(cnt['a'] + cnt['i'])%mod;
            int a = (cnt['e'] + cnt['i'] + cnt['u'])%mod;
            int i = (cnt['e'] + cnt['o'])%mod;
            int o = (cnt['i'])%mod;
            int u = (cnt['i'] + cnt['o'])%mod;
            cnt['a'] =a;
            cnt['e'] =e;
            cnt['i'] =i;
            cnt['o'] =o;
            cnt['u'] =u;
        }
        long ans = 0;
        for (auto c : string("aeiou")){
            ans = (ans + cnt[c])%mod;
        }
        return ans;
    }
};