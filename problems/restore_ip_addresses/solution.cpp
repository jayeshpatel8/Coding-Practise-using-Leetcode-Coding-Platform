class Solution {
public:
int N;
vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
      N = s.size();
      backtrack(s,string(),0);
      return ans;  
    }
    void backtrack(string s, string ip, int i, int part = 0){
        if (part >= 4) {
            if (part ==4 && i == N) {
                ip.pop_back();
                ans.push_back(ip);
            }
            return;
        }
        if (s[i]=='0'){
            backtrack(s, ip=ip+"0.",++i,part+1);            
            return;
        }
        for (int c = 1;c<=3 && i+c <=N; c++){
            string str = s.substr(i,c);            
            int num = stoi(str);
            if (num > 255) return;
            backtrack(s, ip+str+'.',i+c,part+1);            
        }
    }
};