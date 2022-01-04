class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0) return 1;
        return (~n) & (1UL<< setMsb(n))-1;
    }
    int setMsb(int n){        
        for (int i=31; i>=0; i--){
            if (n & (1<<i)) return i+1;
        }
        return 0;
    }
};