class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int i =0;
        for (auto c  : s){
         if( i > 1 && ans[i-2] == c && ans[i-1]==c) continue;
         ans+=c;
         i++;
        }
        return ans;
    }
};
