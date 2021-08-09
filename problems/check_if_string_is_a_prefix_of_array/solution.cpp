class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string prefix;
        unordered_set<string>  set;
        string s1;
        for (auto c : s){
            s1.push_back(c);
            set.insert(s1);
        }
        for (auto w : words){
            prefix += w;
            if (prefix  ==  s) return true;
            else if (set.count(prefix) == 0) return false;
        }
        return false;
    }
};