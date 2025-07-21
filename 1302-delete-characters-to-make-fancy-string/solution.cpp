class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char ch = 'A';
        int cnt=0;
        for (auto c :  s){
            if (c == ch) cnt++;
            else cnt=1, ch=c;
            if (cnt >2)
                continue;
            
            ans.push_back(c);
        }
        return ans;
    }
};
