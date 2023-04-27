class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i=0; i<=num; i++){
                int j = 0,k=i;
                while (k>0) 
                    j = j * 10 + k%10, k/=10;
            if (i+j == num) return true;
        }
        return false;
    }
};