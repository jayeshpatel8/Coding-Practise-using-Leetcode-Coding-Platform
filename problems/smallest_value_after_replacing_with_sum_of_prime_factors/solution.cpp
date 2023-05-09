class Solution {
public:
    int smallestValue(int n) {
        int prev=n;
        while (1){
            
            int sum = 0,i=2;
            while (n>1){
                if (n%i) {i++;continue;};
                sum += i;
                n/=i;
            }
            n=sum;
            if (sum ==prev) break;
            else prev= sum;
        }
     return n;   
    }
};