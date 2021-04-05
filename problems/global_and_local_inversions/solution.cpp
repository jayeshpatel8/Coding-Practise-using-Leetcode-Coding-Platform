class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
       int N = A.size();
        for (int i=0; i<N; i++){
            if (A[i] == i ) continue;
            if (i+1 < N && A[i]==i+1 && A[i+1]==i) i++;
            else 
                return false;
        }        
        return true;        
    }
};