class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
     
        int N = A.size(), slice=0;
        if (N<3) return 0;
        int diff = A[0]-A[1],start=0;
        int i=2;
        for (; i<N; i++){
            if(diff!= (A[i-1]-A[i])){
                if (i-start>=3){
                    int n = i-start-2;
                    slice += (n * (n+1))/2;
                }
                diff = A[i-1]-A[i];
                start = i-1;
            }
        }
        if (i-start>=3){
            int n = i-start-2;
            slice += (n * (n+1))/2;
        }        
        return slice;
    }
};