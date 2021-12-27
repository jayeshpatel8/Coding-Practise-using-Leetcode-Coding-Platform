class Solution {
public:
    int findComplement(int num) {
        return (~num & ( 1U << msb(num))-1);
    }
    int msb(int n){
        int i=0; 
        for (int j=31; j>=0; j--)
            if (n & (1<<j))
                return j;
        return 0;
    }
};