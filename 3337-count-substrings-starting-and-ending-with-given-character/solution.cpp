class Solution {
public:
    long long countSubstrings(string s, char c) {
        int cnt = 0;
        for (auto ch : s) cnt += c ==ch;
        
        return (long) cnt  * (cnt + 1) / 2;
    }
};
