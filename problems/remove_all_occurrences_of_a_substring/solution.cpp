class Solution {
public:
    string removeOccurrences(string s, string part) {
        auto i = s.find(part);
        if (i == string::npos) return s;
        if (i==0)
            return  removeOccurrences(s.substr(part.size()),part);
        return removeOccurrences(s.substr(0,i) + removeOccurrences(s.substr(i+part.size()),part),part);
    }
};