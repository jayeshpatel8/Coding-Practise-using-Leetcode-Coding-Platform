class Solution {
public:
    string makeGood(string s) {
        int d = 'A'-'a';
        string ans;
        for (auto c : s){
            if (!ans.empty()){
                if ((c + d == ans.back()) || (c-d == ans.back())) {
                    ans.pop_back(); continue;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};
