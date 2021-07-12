class Solution {
public:
    bool isIsomorphic(string s, string t) {
       vector<int> pos1(128,-1),pos2(pos1);
        for (auto i=0 ; i<s.length(); i++){

            if ( pos1[s[i]] != pos2[t[i]]) return false;
            pos1[s[i]] = pos2[t[i]] = i;
        }
        return true;
    }
};