class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> M;
        vector<vector<string>> ans;
        for (auto &s : strs){
            string s1 = s;
            sort(begin(s1),end(s1));            
            if (M.count(s1))
                ans[M[s1]].push_back(s);
            else{
                M[s1]=ans.size();
                ans.push_back({s});
            }
        }
        return ans;        
        /*
        unordered_map<string,vector<string>> M;
        for (auto &s : strs){
            string s1 = s;
            sort(begin(s1),end(s1));            
            M[s1].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &  [k, v] :  M)
            ans.push_back(v);
        return ans;
        */
    }
};