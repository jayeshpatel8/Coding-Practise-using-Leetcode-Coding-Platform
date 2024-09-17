class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
         unordered_map<string, int> f;
        istringstream s(s1 + " " + s2);
        while (s >> s1) f[s1]++;
        
        for ( auto &[ss,v] :f){
            if ( v == 1) ans.push_back(ss);
        }
        return ans;
    }
};
