class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        auto c1 = s[0] ,c2= s[3];
        auto r1 = s[1] , r2 = s[4];
        for (;c1<=c2;c1++)
            for (auto r = r1;r<=r2; r++){
                string s2; s2+=c1; s2+=r;
                ans.push_back(s2);
            }
        return ans;
    }
};