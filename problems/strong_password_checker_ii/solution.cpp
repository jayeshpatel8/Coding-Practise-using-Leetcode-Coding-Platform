class Solution {
public:
    bool strongPasswordCheckerII(string pa) {
        int n = pa.size();
        if (n <8) return false;
        string st = "!@#$%^&*()-+";
        int sp=0,small=0,big=0,dig=0;
        for (int i=0; i<n; i++){
            if (i>0 && pa[i] == pa[i-1]) return false;
            auto c = pa[i];
            if (c >='a' && c<='z') small++;
            if (c >='A' && c<='Z') big++;
            if (c >='0' && c<='9') dig++;
            if (st.find(c) != string::npos) sp++;
        }
        return (sp && small && big && dig) ;
    }
};