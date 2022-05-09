class Solution {
public:
    vector<string> letterCombinations(string digits) {
           vector<string> ch={"","","abc", "def", "ghi", 
                                  "jkl", "mno","pqrs",
                                  "tuv","wxyz"};
        vector<string> ans;
        
        for (auto d : digits){
            vector<string> t;
            if (ans.empty()){
                   for (auto &s : ch[d-'0']){
                        t.push_back(string(1,s));
                    }
            }
            else{
                for (auto &a : ans){
                    for (auto &s : ch[d-'0']){
                        t.push_back(a+s);
                    }
                }
            }
            ans.swap(t);
        }
        return ans;
    }
};