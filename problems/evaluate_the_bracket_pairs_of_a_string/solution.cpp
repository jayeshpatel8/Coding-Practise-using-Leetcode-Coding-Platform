class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string> dict;
        
        for(auto w : k) dict[w[0]]=w[1];
        string ans;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='('){
                string w;
                while(s[++i] != ')'){
                    w +=s[i];
                }                
                if (dict.count(w)) ans +=dict[w];
                else ans +='?';
            }
            else
                ans += s[i];
        }
        return ans;
    }
};