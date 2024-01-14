class Solution {
 public:
  int maxPartitionsAfterOperations(string s, int k) {
    if (k == 26) {
      return 1;
    }
    const int n = s.size();
    vector<int> pr(n + 1);
    vector<int> prk(n + 1);
    vector<int> su(n + 1);
    vector<int> suk(n + 1);
    {
      int b = 0;
      int p = 0;
      for (int i = 0; i < n; ++i) {
        int x = s[i] - 'a';
        if (b >> x & 1 ^ 1) {
          b |= 1 << x;
        }
        if (__builtin_popcount(b) > k) {
          b = 1 << x;
          ++p;
        }
        pr[i + 1] = p;
        prk[i + 1] = b;
      }
    }
    {
      int b = 0;
      int p = 0;
      for (int i = n - 1; i >= 0; --i) {
        int x = s[i] - 'a';
        int y = b >> x & 1 ^ 1;
        if (b >> x & 1 ^ 1) {
          b |= 1 << x;
        }
        if (__builtin_popcount(b) > k) {
          b = 1 << x;
          ++p;
        }
        su[i] = p;
        suk[i] = b;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int t = pr[i] + su[i + 1];
      int pc = __builtin_popcount(prk[i]);
      int sc = __builtin_popcount(suk[i + 1]);
      int orc = __builtin_popcount(prk[i] | suk[i + 1]);
      if (orc + 1 <= k) {
        t += 1;
      } else if (pc == k and sc == k and orc < 26) {
        t += 3;
      } else {
        t += 2;
      }
      ans = max(ans, t);
    }
    return ans;
  }
};
