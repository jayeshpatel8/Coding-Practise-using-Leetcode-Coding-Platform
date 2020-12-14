class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
       int r=m ;
       // if (!r|| m==n || m+1==n) return r;
       
         while ( r  && n>=m ){                          
             r = r & (n);
             n &= n-1;
         }
        return r;
    }
};

//1 1101 
//1 1111
//1 1101
// 1100
// 1000