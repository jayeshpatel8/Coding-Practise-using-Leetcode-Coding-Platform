vector<int> sq;
class Solution {
public:
    int punishmentNumber(int n) {
        if (sq.empty()){
            sq.resize(1001);
            for (int i=1; i<=1000; i++){
                int j  = i*i;
                auto s = to_string(j);
                if (punish(s,0,i)) sq[i]=j;
            }
        }
        return accumulate(begin(sq),begin(sq)+n+1,0);
    }
    bool punish(string &s , int i, int n){
        if (i==s.size()) return n==0;
        if (n<0) return false;        
        int n2=0;
        for (; i<s.size(); i++){
            n2 = n2* 10 + s[i]-'0';
            if (punish(s,i+1,n-n2) )
                return true;
        }
        return (n2==n);
    }
};