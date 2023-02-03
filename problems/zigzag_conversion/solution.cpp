class Solution {
public:
    string convert(string s, int numRows) {
        string ans[numRows];
        for (int r=0; r<s.size(); ){
            for (int j=0; j<numRows  && r<s.size(); j++)
                ans[j] += s[r++];
            for (int j=numRows-2; j>0 && r<s.size(); j--)
                ans[j] += s[r++];
        }
        string a;
        for (auto str : ans)
             a+=str;
        
        return a;
    }
};