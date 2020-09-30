class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> c;
        partition(s,0,c);
        return r;
    }
    void partition(string &s,int i,vector<string> &c){
        if (i ==s.length()) {r.push_back(c); return;}
        
        for (int j=i; j< s.length();j++){
            if (!isPal(s.substr(i,j+1-i))) continue;
            c.push_back(s.substr(i,j+1-i));
            partition(s,j+1,c);
            c.pop_back();
        }
    }
    bool isPal(string s){
        int i=0,j=s.length()-1;
       
        while(i<j)
            if(s[i++]!=s[j--]) return false;
        
        return true;
    }
    vector<vector<string>> r;
};