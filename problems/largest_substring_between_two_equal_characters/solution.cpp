class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int map[26]=  {}, ans = -1;
        for ( int  i = 0 ; i< s.size(); i++){
            int c = s[i] - 'a';
            if (map[c] ){
                ans = max (ans, i - map[c]);
            }
            if (map[c] == 0)
                map[c] =  i+1;
        }
        return ans;
    }
};