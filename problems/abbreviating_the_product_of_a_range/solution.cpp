class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long prefix = 1, suffix = 1;
        int digit=0, zeros=0;
        
        for (int i=left; i<=right; i++){
            prefix *= i; suffix *=i;
            for (; prefix >= 1e12; digit++, prefix /=10);
            for (; suffix % 10 == 0; zeros++, suffix /=10);
            if(suffix >= 1e10) suffix %=(long)1e10;
        }
        for (; prefix >= 1e5; digit++, prefix /=10);
        digit += log10(prefix);
        if (digit - zeros < 10)return to_string(suffix) + "e" + to_string(zeros);
        suffix %= (int)1e5;
        return to_string(prefix) + "..." + string(5-to_string(suffix).size(), '0') + to_string(suffix) + "e" + to_string(zeros);
    }
};