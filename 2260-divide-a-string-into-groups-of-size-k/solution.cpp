class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        for (int i=0,j=0; i<n; i+=k){
            
            if (i+k <= n){
                ans.push_back(s.substr(i,k));                
            }
            else{
                string a;
                a = s.substr(i) +string( k-(n-i),fill);
                ans.push_back(a);
                
            }
        }
        return ans;
    }
};
