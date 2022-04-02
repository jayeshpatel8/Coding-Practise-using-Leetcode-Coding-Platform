class Solution {
public:
    long long numberOfWays(string s) {
        
        vector<long long> cnt(2);
        long long zero=0,one=0 ,ans=0;
        for (auto c : s){
            if (c == '0'){
                ans +=cnt[1];
                cnt[0] += one;
                zero++;
            }
            else{
                ans +=cnt[0];
                cnt[1] += zero;
                one++;
            }
        }
   
        return ans;
    }
};