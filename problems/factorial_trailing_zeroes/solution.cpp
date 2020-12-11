class Solution {
public:
    int trailingZeroes(int n) {

    uint64_t numberOfFives = 0;
    
    while (n >= 5) {
        numberOfFives += (n / 5);
        n = (n / 5);
    }
    
    return numberOfFives;        
        return numberOfFives;
    }
    int fa[100]={0};
    uint64_t fact (uint64_t n){
        if (n<2) return 1;
        if (fa[n]) return fa[n];
        return fa[n] = (n * fact (n-1));
    }
};