class Solution {
public:
    double nthPersonGetsNthSeat(int n1) {
        double n = n1;
     return  n == 1 ? 1 :  (1/n + (n-2)/n * nthPersonGetsNthSeat(n-1)); 
    }
};