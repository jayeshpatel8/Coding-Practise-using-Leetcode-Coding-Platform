class Solution {
public:
    int alternateDigitSum(int n) {
        int i=0, sum [2]={0};
        while (n ){
            sum [i&1] += n%10;
            n/=10;i++;
        }
        if (i & 1) return sum[0] - sum[1];
        else return sum[1] - sum[0];

    }
};