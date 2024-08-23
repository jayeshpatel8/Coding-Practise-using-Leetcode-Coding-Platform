class Solution {
public:
    string fractionAddition(string s) {
        int n = 0,d=1,  c=0,c1=0,c2=0;
        if (s[0] != '-') s = '+'  +s;
        while (c   < s.size()){
            for (c1 = c+1; s[c1] != '/'; c1++);
            for (c2 = c1+1; c2 < s.size() && s[c2] != '+' && s[c2] != '-';c2++);
            auto nn = stoi(s.substr(c+1,c1-c1-1)), dd = stoi(s.substr(c1+1,c2-c1-1));
            auto g = gcd((d),dd);
            n = n *dd / g + (s[c] == '-' ? -1 : 1) * nn *d/g;
            d *=dd/g;
            c=c2;
            
        }
        auto g = gcd(abs(n),d);
        return to_string(n/g) + "/" +to_string(d/g);
    }
};
