class Solution {
public:
    int fib(int n) {
        int f1=0,f2=1 ;
        for (int i=2; i<=n; i++){
            int t = f2;
            f2 +=f1;
            f1=t;
        }
        return n==0? 0 : f2;
    }
};