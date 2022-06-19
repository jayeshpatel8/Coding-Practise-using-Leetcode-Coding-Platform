class Solution {
public:

        int minimumNumbers(int sum, int k) {
        if (!sum)
            return 0;

        for (int i=1; i<=100; ++i) {
            if ((k*i)%10==sum%10 && k*i<=sum) {                  
                return i;
            }
        }
           
        return -1;
    }
};