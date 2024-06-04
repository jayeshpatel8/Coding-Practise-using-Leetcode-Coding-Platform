class Solution {
public:
    int longestPalindrome(string s) {
        int f[256]={0};
        for (auto c : s) f[c]++;
        int odd=false, ans =  0;
        for (int i=0; i<256; i++){
            if (f[i] > 0){
                if (f[i] & 1){
                    odd=1;
                    f[i]-=1;
                    
                }
                ans +=f[i];
            }
        }
        return ans + odd;
    }
};
