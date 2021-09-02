class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        long end1 =0, end0 = 0,  mod = 1e9 + 7;
        
        for( auto &i : binary){
            if (i == '1')
                end1 = (end1 + end0 + 1)%mod;
            else
                end0 = (end1 + end0)%mod;
        }
        return (end1 + end0 + (end0 != 0 || binary[0]=='0'))%mod;
    }
};