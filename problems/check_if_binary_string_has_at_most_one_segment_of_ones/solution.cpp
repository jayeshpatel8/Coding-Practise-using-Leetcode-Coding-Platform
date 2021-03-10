class Solution {
public:
    bool checkOnesSegment(string s) {
        int sz = s.size();
        int i=1;
        for (; i<sz; ) if (s[i++]=='0') break;
        for (; i<sz; ) if (s[i++]=='1') return false;
        return true;
    }
};