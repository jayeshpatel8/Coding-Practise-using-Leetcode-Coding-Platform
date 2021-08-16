class Solution {
public:
    bool checkRecord(string s) {
     int a=0, l=0;;
        for (auto c : s){
            if ( (a += c == 'A') > 1) return false;
            if ( c == 'L' ) l++;
            else l=0;
            if (l>2) return false;
        }
        return true;
    }
};