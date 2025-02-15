vector<int> sq;
class Solution {
public:
    int punishmentNumber(int n) {
        if (sq.empty()){
            sq.push_back(0);
            for (int i=1; i<=1000; i++){
                auto j = i * i;
                auto s  = to_string(j);
                if(punish(s,0,i))
                    sq.push_back(j) ;
                else
                    sq.push_back(0) ;
            }
        }
        return accumulate(begin(sq),begin(sq)+n+1,0);
    }
    bool punish(auto & s, int i, int n){
        if (i==s.size() || n< 0) return n==0;
        int n2=0;
        for ( ; i<s.size(); i++)
        {
            n2 = n2* 10 + s[i]-'0';
            if ( punish(s,i+1, n-n2))return true;
        }
        return n2==n;
    }
};
