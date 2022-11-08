class Solution {
public:
    string makeGood(string s) {
        string s1;
        for (auto c : s){
            if (tolower(c) == tolower(s1.back())){
                if (c == s1.back()) {s1.push_back(c) ; continue; }
                s1.pop_back();
            }
            else
            s1.push_back(c) ;
        }
        return s1;
    }
};