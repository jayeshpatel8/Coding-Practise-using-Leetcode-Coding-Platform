class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> s;
        
        string str;
        stringstream X(path);
        while(getline(X,str,'/')){
            
            if (str=="/" || str==".") continue;
            if (str == "..") {
                if (!s.empty())s.pop_back();
                continue;
            }
            if (str.size())
                s.push_back(str);
        }

        string res;
        
        //cout << res<<" ,";

         for(auto str : s) {res += "/"+str;}
        return res.empty() ? "/" : res;
    }
};