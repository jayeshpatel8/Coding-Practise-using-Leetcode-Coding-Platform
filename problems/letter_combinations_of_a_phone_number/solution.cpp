class Solution {
public:
    unordered_map<char,string> m;
    vector<string> ans;
    string c;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        // BFS        
        for (auto &s : digits){
            if (ans.empty()){
                for (auto c : m[s])
                    ans.push_back(string(1,c));
            }
            else{
                vector <string> t;
                for (auto &s1 : ans){
                    for (auto c : m[s]){
                        s1.push_back(c);
                        t.push_back(s1);
                        s1.pop_back();
                    }
                }
                ans.swap(t);
            }
        }
        //dfs(digits,0);
        return ans;
    }
    void dfs(string & s, int i){
        if (i== s.size()){
            ans.push_back(c);
            return;
        }
        for (auto ch : m[s[i]]){
            c.push_back(ch);
            dfs(s,i+1);
            c.pop_back();
        }
    }
};