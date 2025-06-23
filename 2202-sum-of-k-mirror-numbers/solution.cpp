class Solution {
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        
        for ( int i=1; n> 0 && i<10; i++){
            if (check(k,i)) 
                ans +=i, n--;
        }
        int num=1 ,end=10;
        while(n){
            
            // 1 1- 9 9,  10 01-99 99, 100 001 - 999 999
            for (long long i = num; n > 0 && i<end; i++)
            {
                int rnum=0, j=i;
                while(j > 0){
                    rnum = rnum * 10 + j % 10;
                    j /= 10;
                }
                if ( check(k,i * end + rnum))
                    ans  += i * end + rnum, n--;  
               
            }
            for (long long i = num; n > 0 && i<end; i++)
            {
                int rnum=0, j=i;
                while(j > 0){
                    rnum = rnum * 10 + j % 10;
                    j /= 10;
                }                           
                //1 0 1-9 9 9,  10 [0-9] 01 
                for (long long m = 0 , t = i * end * 10+ rnum; n>0 && m<10; m++)
                    if ( check(k, t + m * end) )
                        ans += t + m * end, n--;  
            }            
            num =end, end *=10;
        }
   
        return ans;
    }
    bool check(int kbase, long long num){
     string s;
        
        while(num){
            s += (char) (num%kbase);
            num /=kbase;
        }
       for ( int i=0 , j= s.size()-1; i<j; ){
           if (s[i++] != s[j--])
               return false;
       }
    
        return true;
    }
};
