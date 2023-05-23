class Solution {
public:
    int minLength(string s) {
        string ans;
        bool f=true;
        while(f){
            f=false;            
            ans="";
            for (int i=0; i<s.size(); i++){
                if (s[i]=='A' && i+1<s.size() && s[i+1]=='B')i++,f=true;
                else if (s[i]=='C' && i+1<s.size() && s[i+1]=='D')i++,f=true;
                else 
                    ans.push_back(s[i]);                    
            }
            s=ans;
        }
        return ans.size();
    }
};