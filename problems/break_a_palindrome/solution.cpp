class Solution {
public:
    string breakPalindrome(string pal) {
        int N = pal.size();
        if (N==1) return {};
        //int m = N&1? N/2 : -1;
        for (int i=0; i<N/2; i++){            
            if (pal[i]=='a') continue;
            pal[i]='a';
            return pal;
        }
        pal[N-1]='b';
        return pal;
    }
};