class Solution {
public:
    int minFlips(int a, int b, int c) {
        if ((a|b) == c) return 0;
        int ans = 0;
        for ( int i=0; i<31; i++){
            int bit =  1u << i;
            int abit = (a & bit), bbit= (b & bit), cbit = c &bit;
            if (  (abit|bbit) == cbit ) continue;
            if (cbit ) ans++;
            else{
                ans += (abit != 0) + (bbit != 0);
            }
        }
        return ans;
    }
};