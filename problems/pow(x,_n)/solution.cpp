class Solution {
public:
    double myPow(double x, int n) {
        
       
        if (n==0 || x==1) return 1;
        if (n==1) return x;
        else if (n==-1) return 1/x;
               
        
        return (n%2? (n<0)?1/x:x:1) * myPow(x*x,n/2);
    }
};