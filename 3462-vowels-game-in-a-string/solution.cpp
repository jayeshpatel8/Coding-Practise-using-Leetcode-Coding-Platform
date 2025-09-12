class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};;
        for (auto c : s){
            if (v.count(c)) return true;
        }
        return false;
    }
};
