class Solution {
public:
    bool isFascinating(int n) {
        
        int f[10]={};
        int n1=n;
        for (int i=1; i<4; i++){
            n=i*n1;
            while (n>0) 
                f[n%10]++, n/=10;
        }
        
        if (f[0]) return false;
        for (auto i=1; i<10; i++) if (f[i] != 1) return false;
        return true;
    }
};