class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        unsigned long rem = 0;
        for (auto c : word)   {
            rem = rem * 10 +  (c-'0');
            rem %= m;
            ans.push_back(rem == 0);
        }
        return ans;
    }
};