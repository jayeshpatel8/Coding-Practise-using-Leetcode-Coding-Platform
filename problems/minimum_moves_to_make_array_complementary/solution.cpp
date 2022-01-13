class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int N = nums.size();
        vector<int> sum(limit*2 + 2, 0);
        for (int i=0; i<N/2; i++){
            int a = nums[i], b = nums[N-i-1];
            /* 
                Target Sum T 
                T==2   (T<min(a,b)+1 )       T == (a+b)  T>(a+b)  T > (max(a,b)+limit+1)
 sum (swap )    2         -1             -1    0            +1     +1     
       for (3,5) limit = 6
             T  2         4                    8          9         11    
           swap 2         -1                    -1         +1        +1   
                2          1                    0           1        2   
            */
            sum[2]+=2;
            sum[min(a,b)+1]--;
            sum[a+b]--;
            sum[a+b+1]++;
            sum[max(a,b)+limit+1]++;
        }
        int ans =INT_MAX, psum=0;
        for (int i=2; i<=2*limit; i++){
            psum += sum[i];
            ans = min(ans, psum);
        }
        return ans;
    }
};