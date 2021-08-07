class Solution {
public:
    //"ddddeeeee"
    string makeFancyString(string s) {
        string ans;
        for (int i=0, j=0; i<s.size(); i++){
            ans.push_back(s[i]);
            if (i> 0 && s[i] == s[i-1]){                
                while(i+1 < s.size() && s[i] == s[i+1]){
                    i++;
                }
            }
        }

        return ans;
    }
};