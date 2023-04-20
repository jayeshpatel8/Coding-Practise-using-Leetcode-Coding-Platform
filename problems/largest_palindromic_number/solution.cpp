class Solution {
public:
    string largestPalindromic(string num) {
        int ch[127]={};
        for (auto c : num) ch[c]++;
        string ans;
        for (int i='9'; i>='0'; i--){
            if (ch[i]&1){
                ans.push_back(i); break;
            }
        }   
        int s  = accumulate(begin(ch)+'1', begin(ch)+'9'+1,0);
        if (s==0) return "0";
        //if (!ans.empty() && ch['0']) 
        for (int i='0'; i<='9'; i++){
            if (ch[i] >= 2 ){
                int c = ch[i]/2;
                string s = string(c,i);
                ans = s + ans + s;
            }
        }
        int i=0, j=ans.size()-1;
        for (; i<=j; i++,j--){
            if (ans[i]!= '0' || i==j){
                return ans.substr(i,j-i+1);
            }
            
        }
        
        return ans;
    }
};