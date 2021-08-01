class Solution {
public:
    //long long mod = 1e18 + 7;
    long long numberOfWeeks(vector<int>& ms) {        
        long long max = *max_element(begin(ms),end(ms)), sum =accumulate(begin(ms),end(ms),0ll);
       if (2 * max  > sum) return 2 * (sum - max) + 1;
        return sum;
    }
};