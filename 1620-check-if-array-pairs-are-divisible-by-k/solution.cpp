class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rem(k);
        for (auto i : arr) {
            int r = i % k;
            if (r<0) r+=k;
            rem[r]++;
        }
        if (rem[0] %2) return false;
        for ( int i=1; i<k; i++)
            if (rem[i] != rem[k-i]) return false;  // (a+b)%k = [a%k] + [b%k] =k  => b%k = k  - a%k => freq of a%k == freq of b%k
        return true;
    }
};
