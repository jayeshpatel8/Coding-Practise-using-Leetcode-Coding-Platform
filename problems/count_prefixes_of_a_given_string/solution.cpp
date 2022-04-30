class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans= 0 ;
        for (auto &w : words){
            int j=0;
            for (;j<w.size() && j <s.size();j++){
                if (w[j] != s[j])
                    break;
            }
            ans += j ==w.size();
        }
        return ans;
    }
};