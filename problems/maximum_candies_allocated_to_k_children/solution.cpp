class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long l=0, r  = *max_element(begin(candies), end(candies));
        while (l<r){
            long long m = l + (r-l +1)/2;
             if (istrue(candies,m,k) ==false){
                 r = m -1;
             }
            else
                l = m ;
        }
        return l;
    }
    bool istrue(vector<int>& candies, long long   m, long long k){
        long long ans = 0;
        for (auto & i : candies){
            ans += i /m ;
        }
        return ans >= k;
    }
};