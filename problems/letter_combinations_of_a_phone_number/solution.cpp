class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string d[8] = {"abc","def","ghi",
                       "jkl","mno","pqrs",
                       "tuv","wxyz"
                      }; 
        
        for (auto c  : digits){
            vector<string> res;
            for (auto c1 : d[c-'2']){
                    
                if (ans.size()==0){
                    string s="";
                    s += c1;
                    res.push_back(s);
                    
                }
                else{
                    for (auto s : ans){
                        res.push_back(s+c1);
                    }
                }
            }
            ans=res;
        }
        return ans;
    }
};