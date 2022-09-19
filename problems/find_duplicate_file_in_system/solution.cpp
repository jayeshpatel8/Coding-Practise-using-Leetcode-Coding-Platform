class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
      unordered_map<string, vector<string>> M;
        for (auto &p : paths){
            stringstream ss(p);
            bool dir= true;
            string s, dir_name;
            while (getline(ss,s,' ')){
                if (dir){
                    dir=false;
                    dir_name = s;
                }
                else{
                    auto it = s.find('(');
                    string file = dir_name + '/' + s.substr(0,it++);
                    string content = s.substr(it);
                    content.pop_back();
                    M[content].push_back(file);                    
                }
            }
        }
        vector<vector<string>> ans;
        for (auto &[k,v] : M){
            if (v.size() >  1){
                ans.push_back(v);
            }
        }
        return ans;
    }
};