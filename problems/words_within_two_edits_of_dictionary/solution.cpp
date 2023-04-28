class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& d) {
        vector<string> ans;
        unordered_set<string> st(begin(d),end(d));
        for (auto &q :queries){
            for (auto s : d){
                int cnt=  0;
                for (int i=0; i<q.size(); i++)
                    cnt+= q[i] != s[i];
                if (cnt <3){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};