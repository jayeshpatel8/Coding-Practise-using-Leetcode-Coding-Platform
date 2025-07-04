class Solution {
public:
    char kthCharacter(long long k, vector<int>& A) {
        int res = 0, n = A.size();
        k -= 1;
        for (int i = 0; i < n && i < 60; ++i)
            if ((k >> i) & 1)
                res += A[i];
        return 'a' + res % 26;
    }
};
