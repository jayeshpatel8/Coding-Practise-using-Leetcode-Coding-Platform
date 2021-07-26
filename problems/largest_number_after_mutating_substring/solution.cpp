class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool changed=false;
        for ( auto &c : num){
            int newch = change[c-'0'] + '0';
            if (c <  newch)
                changed = c = newch;
            else if ( changed && c >  newch )
                break;
        }
        return num;
    }
};