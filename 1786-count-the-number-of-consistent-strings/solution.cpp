class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int c=0;
        for (auto ch : allowed) c |= 1 << (ch - 'a');
        int ans = 0;
        for (auto s  : words){
            int c1 = 0;
            for (auto ch : s){
                c1 |= 1 << (ch - 'a');
            }
            ans += (c1& c) == c1;
        }
        return ans;
    }
};
