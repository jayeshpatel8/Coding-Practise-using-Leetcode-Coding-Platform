class Solution {
public:
    int maxOperations(string s) {
        int res = 0, ones = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            ones += s[i] - '0';
            if (i > 0 && s[i] < s[i - 1])
                res += ones;
        }
        return res;
    }
};
