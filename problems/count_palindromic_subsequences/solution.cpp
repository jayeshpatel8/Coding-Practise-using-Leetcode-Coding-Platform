class Solution {
public:
    int prefix[10001][10][10]={}, suffix[10001][10][10]={};
    int ans = 0 , mod= 1e9 + 7;
    int countPalindromes(string s) {
        int c[10]={};
        vector<int> dig(10);
        iota(begin(dig),end(dig),0);
        for (int i=0; i<s.size(); i++){
            auto ch = s[i]-'0';
            {
                for (auto d1 : dig)
                for (auto d2 : dig){
                    prefix[i][d1][d2] = i>0 ? prefix[i-1][d1][d2] :  0;
                    if (d2 == ch)
                        prefix[i][d1][d2] += c[d1];
                }
            }

            c[ch]++;
        }   

        int c1[10]={};
        for (int i=s.size()-1; i>=0; i--){
            auto ch = s[i]-'0';
                for (auto d1 : dig)
                for (auto d2 : dig){
                    suffix[i][d1][d2] = i<s.size()-1 ? suffix[i+1][d1][d2] :  0;
                    if (d2 == ch)
                        suffix[i][d1][d2] += c1[d1];                   
                }           

             c1[ch]++;
        }   

        for (int i=2; i< (int)s.size()-2; i++){
            for (auto d1 : dig)
                for (auto d2 : dig){
                    auto sum = (1l * prefix[i-1][d1][d2] * suffix[i+1][d1][d2])%mod;
                    ans= (ans + sum) %mod;
                }
        }
        return ans;
    }
};