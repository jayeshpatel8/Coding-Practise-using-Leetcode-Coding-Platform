class Solution {
public:
    bool judgeSquareSum(int c) {
        if ((int)sqrt(c) * (int)sqrt(c) == c) return true;
        int maxn = sqrt(c)+1;
        
        size_t i =0, j= maxn;
        size_t n1=0,n2=j*j;
        while(i<=j){
            if (n1+n2 > c ) n2 = (--j)*j;
            else if (n1+n2 < c) n1 = (++i)*i;
            else return true;
        }
        return false;
    }
};
