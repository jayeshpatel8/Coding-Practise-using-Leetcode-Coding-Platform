class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0, p = pref.size();;
        for (auto & w : words){
            int w1 = w.size();
            if (w1 < p) continue;
            ans += (pref == w.substr(0,p));
        }
        return ans;
    }
};