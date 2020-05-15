
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    vector<string> v;
    string ip;
    restoreIpAddresses(s,0,ip,v,0);
        return v;
    }
void restoreIpAddresses(string s,int idx,string ip,vector<string>&v,int depth){

    if (depth >4) return;
    if (depth ==4 && idx ==s.size()) { ip.erase(ip.end()-1);v.push_back(ip); return;}
    for (int i=1; i<=3;i++){
        if (idx+i > s.size() ) return;
        if (s[idx]=='0' && i>1) return;
        
        string sub = s.substr(idx,i);
        int n = stoi(sub);
        if (n >255) return;
        restoreIpAddresses(s,idx+i,ip+sub+'.',v,depth+1);
    }
}
};


