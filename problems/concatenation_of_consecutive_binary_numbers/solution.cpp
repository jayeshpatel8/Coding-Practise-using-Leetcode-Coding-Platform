class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 1, mod = 1e9 +7;
        for (int j=2; j<=n; j++){
            int bits = getbits(j);
            ans = ((ans * (1 << bits) ) + j )%mod;
        }
        return ans;
    }
    int getbits(int j){
        int ans = 0;
        while (j )
            ans++, j >>= 1;
        return ans;
    }
};