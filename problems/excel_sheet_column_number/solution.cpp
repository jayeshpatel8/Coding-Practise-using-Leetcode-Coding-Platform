class Solution {
public:
    int titleToNumber(string s) {
     uint64_t r=0;
        for (auto c : s){
            r = r * 26 + c-'A' + 1;
        }
        return r;
    }
};