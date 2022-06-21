class Solution {
public:
    bool isHappy(int n) {
        int sqr[10]={0,1,4,9,16,25,36,49,64,81};
        unordered_set<int>st;
        while (!st.count(n)){            
            st.insert(n);
            int sum = 0;
            while (n ){
                sum += sqr[n%10];
                n/=10;
            }                        
            n = sum;
        }
        return n == 1;
    }
};