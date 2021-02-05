class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        
        int n = path.size();
        for (int i=0; i<n; ){
            if ((i+1 <n && path[i+1]=='/') || i+1 ==n ){i++; continue;}
            auto j = path.find('/',i+1);
            string t;
            if (j == string::npos)  j = n;
            t = path.substr(i,j-i);
            
            if (t=="/.")i+=2;
            else if (t=="/.."){
                if(!s.empty())s.pop();
                i+=3;
            }
            else
            {s.push(t);i =  j;}
        }
        if (s.empty())  return "/";
        string res;
        while (!s.empty()) {res =s.top()+res;s.pop();}
        return res;
    }
};