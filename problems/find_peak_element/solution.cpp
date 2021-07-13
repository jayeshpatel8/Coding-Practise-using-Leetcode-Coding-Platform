class Solution {
public:
    int findPeakElement(vector<int>& A) {
        int N = A.size();
        
        int l = 0, r = N-1;
        
        while(l<r){
            int m = (l+r) /2;
            
            if ( A[m] < A[m+1]) l=m+1;
            else r=m;
        }
        return l;
    }
};