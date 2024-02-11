class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int f[26]={}, pair= 0, ans = 0;
        vector<int> sz;
        for (auto &w : words){
            for (auto c : w){
                pair += ++f[c-'a'] % 2 == 0;
            }
            sz.push_back(w.size());
        }
        sort(begin(sz),end(sz));

        for (auto c : sz){
            pair -= c/2;
            if (pair >= 0) ans++;
            else break;
        }
        return ans;
    }
};
