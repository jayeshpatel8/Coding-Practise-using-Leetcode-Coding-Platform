class Solution {
public:
    static constexpr int64_t MOD = 1000000007;
    long long sumScores(string s) {
        const int64_t n = s.length();
        vector<int> z(n);
        for ( int i=0,l=0,r=0; i<n; i++){
            if (i>r){
                l=r=i;
                while(r<n && s[r-l] == s[r]) r++;
                z[i] = r-l;
                r--;
            }
            else{
                int i1 = i-l;
                if (i + z[i1] <= r) z[i] = z[i1];
                else
                {
                    l = i;
                    while(r<n && s[r-l] == s[r]) r++;
                    z[i] = r-l;
                    r--;
                }
            }
        }
        long long sum=n;
        for (int i=1; i<n; i++) sum +=z[i];
        return sum;
    }
        long long sumScores2(string s) {
        const int64_t N = s.length();
        int64_t h1 = 0, h2 = 0, prod = 1, sum = N;
        for (size_t i = 0, j = N - 1; j > 0; ++i, --j) {
            h1 = (h1 * 26 + s[i] - 'a') % MOD;
            h2 = (h2 + prod * (s[j] - 'a')) % MOD;
            prod *= 26, prod %= MOD;
            if (h1 == h2) {
                sum += (i + 1);
            } else {
                size_t p = 0, k = j;
                while(s[p] == s[k]) {
                    ++k, ++p;
                }
                sum += p;
            }
        }
        return sum;
    }
};