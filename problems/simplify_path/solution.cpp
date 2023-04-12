class Solution {
public:
    string simplifyPath(string path) { 
        vector<string> st;
        
        for (int i = 0; i< path.size(); i++){
            if (path[i]=='/') continue;
            string t;
            for (; i<path.size() && path[i] != '/'; i++)
                t += path[i];
            if (t=="..") {
                if (!st.empty()) st.pop_back();
            }
            else if ( t != ".") st.push_back(t);
        }
        string ans;
        for (auto c : st){
            ans+='/'+c;
        }
        if (ans.empty()) ans+='/';
        return ans;
    }
    string simplifyPath2(string path) {
        string ans(1,'/');
        int dot=0;
        for (auto c : path){
            if (c=='/'){
                if (ans.back()==c) ans.pop_back();
            }
            else if (c =='.' && (dot || ans.back()=='/')) 
            {
                dot++;
            }

            if (c !='.' ){
                if ( c== '/' && dot > 0 && dot <=2 ){
                    while (!ans.empty() && ans.back() != '/') ans.pop_back();
                    if (!ans.empty())ans.pop_back();
                    if (dot==2){
                        while (!ans.empty() && ans.back() != '/') ans.pop_back();
                        if (!ans.empty())ans.pop_back();
                    }
                }                       
                dot=0;                               
            }
            ans+=c;                            
        }

        if ( dot > 0 && dot <=2 ){
            while (!ans.empty() && ans.back() != '/') ans.pop_back();
            if (!ans.empty())ans.pop_back();
            if (dot==2){
                while (!ans.empty() && ans.back() != '/') ans.pop_back();
                if (!ans.empty())ans.pop_back();
            }
        }        
        if (ans.back()=='/') ans.pop_back();
        if (ans.empty()) ans.push_back('/');
        return ans;
    }
};