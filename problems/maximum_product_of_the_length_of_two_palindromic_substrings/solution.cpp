class Solution {
public:
    long long maxProduct(string s) {
        int N = s.length();
        vector<int> dp(N), left(N, 1), right(N, 1);;
        for(int i = 0, l = 0, r = -1; i < N; i++){
            int k = (i > r) ? 1 : min(dp[l+r-i], r - i + 1);
            while(0 <= i - k && i + k < N && s[i-k] == s[i+k]){
                left[i+k] = max(left[i+k], 2*k + 1);
                right[i-k] = max(right[i-k], 2*k + 1);
                k++;
            }
            dp[i] = k--;
            left[i+k] = max(left[i+k], 2*k + 1);
            right[i-k] = max(right[i-k], 2*k + 1);
            if(i + k > r){
                l = i - k;
                r = i + k;
            }
        }
        for (int i=1;i<N;++i) left[i] = max(left[i], left[i-1]);
        for (int i=N-2;i>=0;--i) right[i] = max(right[i], right[i+1]);
            
        long long best = 0;
        for (int i=0;i<N-1;++i) {
            best = max(best, (long long)left[i] * (long long)right[i+1]);
        }
        return best;
    }
};