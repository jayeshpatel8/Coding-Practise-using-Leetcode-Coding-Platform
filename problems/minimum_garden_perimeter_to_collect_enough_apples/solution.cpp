class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long n=1;
        /*
        n=3
        ans[n]=0
        for ( i=0 ; i<n ; i++)
           ans[n] += sum of (i+1 to [2*n - (i)])
          
          ==>2 * (2 *  n + 1) * (n*n + n)
        */
        
        while ( neededApples >  2 * (2 *  n + 1) * (n*n + n)){
            n++;            
        }
        return n * 8;
    }
};