class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int N =  arr.size();
        int r = N-1;
        for (; r>0; r--) 
            if (arr[r-1] > arr[r]) break;
        int ans = r;
        for ( int l=0; l<r &&  (l==0 || arr[l-1]<=arr[l]); l++){
            while  ( r < N && arr[l] > arr[r]) r++;
            ans = min(ans, r-l -1);
        }
        return ans;
    }
};
