class Solution {
public:
    int totalMoney(int n) {
        int mday=1;
        int sum=0,k;
        for (int d=1; d<=n; d++){
            if (d%7==1) {
                sum  += mday++;
                k=mday;
            }
            else
                sum += k++;                        
        }
        return sum;
    }
};