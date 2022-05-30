class Solution {
public:
    int divide(int dividend, int divisor) {
        long dvd = labs(dividend) , dvs = labs(divisor);   
        int sign = (divisor > 0) ^ (dividend > 0) ? -1 : 1;
        long cnt=1, ans=0;
        while (dvd >= dvs){
            long t = dvs;cnt=1;
            while (dvd  >= (t << 1)){
                t <<=1;
                cnt<<=1;
            }
            dvd -=t;
            ans +=cnt;
        }
        ans *=sign;
        ans = min<long>(INT_MAX, ans);
        ans = max<long>(INT_MIN, ans);
        return ans;
    }
};