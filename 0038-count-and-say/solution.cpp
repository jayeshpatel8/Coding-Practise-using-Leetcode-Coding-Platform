unordered_map<int,string> M;
class Solution {
public:
    
    string countAndSay(int n) {
        if (n==1) return "1";
        if (n==2) return "11";
        string s,temp="11";
        if (M.count(n)) return M[n];
        for (int i=3 ,cnt = 1; i<=30; i++){
            s=temp + "&";
            temp="";
            cnt = 1;
            for (int j=1,k = 0; j<s.size(); j++){
                if (s[j] == s[k]) cnt++;
                else{
                    temp +=  to_string(cnt);
                    temp += s[k];
                    k=j; 
                    cnt=1;
                }
            }            
            M[i]=temp;
        }
        return M[n];
    }
};
