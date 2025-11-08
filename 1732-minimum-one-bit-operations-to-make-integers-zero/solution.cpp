class Solution {
public:
    int minimumOneBitOperations(int n) {
        // overservation  n = 2^k  then ans = 2 ^(k+1) - 1
        if(n==0) return  0;
        if(n==1) return 1;
        if (n & n-1 == 0) return (n<<1)-1;
        
        int j = 1;
        while(j<=n) j<<=1;
        
        // For 1010 => f(1000) - f(0010)
        return j-1 - minimumOneBitOperations(n - (j>>1));
    }
};
/*
 0100
 0101
 0111
 0011
 0001
 0000 
 0101
 0110
 0111
*/
