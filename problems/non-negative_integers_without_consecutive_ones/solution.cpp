class Solution {
public:
    int findIntegers(int n) {
        int f[32];
        f[0]=1,f[1]=2;
        for (int i = 2; i < 32; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
       int sum=0;
        for (int i = 30,prev=0; i >= 0; i--) {
            if ((n & (1<<i)) ){
                sum +=f[i];
                if (prev) {--sum; break;}
                prev=1;
            }
            else prev=0;
        }
        return sum+1;
    }
};
