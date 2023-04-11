class Solution {
public:
    string removeStars(string s) {
        int i=0,j=0;
        while (i<s.size()){
            if (s[i] !='*') s[j++]=s[i];
            else
                j--;
            i++;
        }
        return s.substr(0,j);
    }
    string removeStars2(string s) {
        string ans;
        for (auto c : s){
            if (c=='*') ans.pop_back();
            else
                ans.push_back(c);
        }
        return ans;
    }
};