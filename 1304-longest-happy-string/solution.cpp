class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        int t = a+b+c, aa=0,bb=0,cc=0;
        for (int i=0; i<t; i++){
            if ((a >= b && a >= c && aa < 2) || (a >0 && (cc ==2 || bb==2))){
                ans += 'a';
                aa++;a--;
                bb=cc=0;
            }
            else if ((b>=a && b >=c && bb <2) || (b >0 && (aa ==2 || cc==2))){
                ans +='b';bb++;b--;
                aa=cc=0;
            }
            else if ((c >=a && c >=b && cc < 2) || (c >0 && (aa ==2 || bb==2))){

                ans +='c';cc++;c--;
                aa=bb=0;
            }
        }

        return ans;
    }
};
