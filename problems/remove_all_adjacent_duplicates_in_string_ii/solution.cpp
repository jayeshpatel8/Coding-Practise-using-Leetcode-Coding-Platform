class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<array<int,2>> ans(1,{'!',0});
        for (int i=0; i<s.size(); i++){
            if (ans.back()[0] != s[i])
                ans.push_back({s[i],1});
            else {
                if (ans.back()[1] == k-1){
                    ans.pop_back();
                }
                else
                    ++(ans.back()[1]);
            }
        }
        string a;
        for (int i=1;i <ans.size(); i++){
            a.append(ans[i][1],ans[i][0]);
        }
        return a;
    }
};