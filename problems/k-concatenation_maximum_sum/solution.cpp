class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int msum=0, n = arr.size(), mod = 1e9 +7;
        for (int i=0, csum=0, N = n * min(2, k); i < N; i++){
            int e = arr[i%n];
            csum = max(csum + e , e);
            msum = max(msum, csum);
        }   
        if (k>2)  return  max<long>(msum, k> 2 ? msum + (long)(k-2) * accumulate(begin(arr),end(arr),0):0 ) %  mod;
        return  msum %  mod;
    }
};