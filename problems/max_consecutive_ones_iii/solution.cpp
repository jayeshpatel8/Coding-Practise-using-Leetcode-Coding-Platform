class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i=0,j=0;
        for (; i<A.size(); i++){
            if(A[i]==0) K--;
            if(K<0 && A[j++]==0){
                K++;
            }
        }
        return i-j;
    }
};