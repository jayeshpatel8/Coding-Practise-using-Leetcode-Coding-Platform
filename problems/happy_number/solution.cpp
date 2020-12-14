class Solution {
public:
    bool isHappy(int n) {
        int limit=100;
        while (n!=1 && --limit){
            int sum = 0;
            while (n){
                    int d = n%10;  n= n/10;   
                    sum += d * d;
                }
            n=sum;
        }
        return n==1;
    }
};