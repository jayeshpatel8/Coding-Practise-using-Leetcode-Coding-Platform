class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for (auto c: s){
            if (isdigit(c)){
                if ( ans.empty() == false) ans.pop_back();
                continue;
            }
            ans.push_back(c);
        }
        return ans;
    }
};
