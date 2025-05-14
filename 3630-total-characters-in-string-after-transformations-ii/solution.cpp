class Solution {
public:
static const int mod = 1e9 + 7;    
    struct Matrix {
        array<array<long long, 26>, 26> m{};
        auto &operator[](int idx) { return m[idx]; }
        auto &operator[](int idx) const { return m[idx]; }
        Matrix operator*(const auto& other) const {
            Matrix res{};
            for (int j = 0; j < 26; ++j)
                for (int k = 0; k < 26; ++k)
                    for (int i = 0; other[k][j] && i < 26; ++i)                    
                        res[i][j] = (res[i][j] + m[i][k] * other[k][j]) % mod;
            return res;        
        }
    };     
    Matrix pow(const Matrix &m, int p) {
        if (p == 1)
            return m;
        auto res = pow(m, p / 2);
        res = res * res;
        return p % 2 ? res * m : res;
    }  
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix m;
        long long cnt[26] = {};
        for (int i = 0; i < nums.size(); ++i)
            for (int j = 0; j < nums[i]; ++j)
                m.m[i][(i + j + 1) % 26] = 1;        
        auto mp = pow(m, t);
        for (int i = 0; i < 26; ++i)
            cnt[i] = accumulate(begin(mp[i]), end(mp[i]), 0LL, [&](auto sum, auto cnt){
                return (sum + cnt) % mod;
            }); 
        return accumulate(begin(s), end(s), 0, [&](int res, char ch){
            return  (res + cnt[ch - 'a']) % mod;
            });
    }
};
