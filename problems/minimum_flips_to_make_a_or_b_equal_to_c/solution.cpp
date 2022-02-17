class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        while (c || b || a){
            if ((c &1) != ((b | a) &1)){
                if (c&1) cnt+=1;
                else
                    cnt += (a&1) + (b&1);
            }
            c>>=1; b>>=1; a>>=1;
        }
        return cnt;
    }
};