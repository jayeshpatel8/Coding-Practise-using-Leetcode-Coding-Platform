class Solution {
public:
int countDigitOne(int n) {
    //Consider the 1s in ones place , tens place, hundreds place and so on... 
        long long int res(0);
        for (long long i=1; i<=n; i*=10){
            long long divider = i * 10;
            res += (n / divider) * i + min (i, max(0LL, n % divider -i + 1));
        }
        return res;
    }
};