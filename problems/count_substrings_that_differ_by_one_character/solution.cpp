class Solution {
public:
    int countSubstrings(string s, string t) {
     int ans=0;
        for (int i=0; i< s.size(); i++)
        {        
            for (int j=0; j<t.size(); j++){
                int a=i, b=j, diff=0;
                while(a<s.size() && b<t.size()){
                    if (s[a++] != t[b++]) diff++;
                    if(diff==1) ans++;
                    else if (diff>1) break;
                    
                }
            }
        }
        return ans;
    }
};