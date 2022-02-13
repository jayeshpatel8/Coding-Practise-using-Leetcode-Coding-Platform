class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long  sum=accumulate(begin(beans),end(beans),0L), ans = sum;
        sort(begin(beans),end(beans));
        for ( long  N = beans.size(), i = N-1; i>=0; i--){
            ans = min(ans, sum -  beans[i] * (N-i));
        }
        return ans;
    }
};