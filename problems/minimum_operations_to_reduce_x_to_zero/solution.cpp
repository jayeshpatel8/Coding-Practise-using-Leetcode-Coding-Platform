class Solution {
public:
    int minOperations(vector<int>& A, int x) {
        x = accumulate(begin(A), end(A),0) - x ;
        if (x == 0) return A.size();
        if (x < 0) return -1;
        // lsum + ..remaining.. + rsum => lsum + rsum = x
        //  find  =  total - x = remaining with largest size
        int ans=-1, total=0,l=0,r=0,N=A.size();
        while ( l<=r){
            if (total < x )  {if (r < N) total +=A[r++]; else break;}
            
            else{
                if (total ==x) ans = max(ans, r-l);                    
                total -=A[l++];
            }         
        }
        return ans == -1 ? -1 : A.size()-ans;
    }
};