class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size()-1;
        for (int i=0; i<n; i++){
            weights[i] += weights[i+1];
        }
        weights.pop_back();
        nth_element(begin(weights),begin(weights) + k - 1, end(weights));
        long long ans = 0;
        for (int i=0; i<k-1; i++)
            ans -= weights[i];
        nth_element(begin(weights),begin(weights) + n - k + 1, end(weights));
        for (int i=n+1-k; i<n; i++)
            ans += weights[i];
        return ans;
    }
};
// 4 8 6
// 8 - 4 = 4 