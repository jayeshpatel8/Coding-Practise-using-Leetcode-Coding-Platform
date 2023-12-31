class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> idx(26, -1);
        int ans = -1;
        for (int i=0; i <s.size(); i++){
            if ( idx[s[i]-'a'] != -1){
                ans= max(ans, i - idx[s[i]-'a']-1);
            }
            else
                idx[s[i]-'a'] = i;
        }
        return ans;
    }
};
