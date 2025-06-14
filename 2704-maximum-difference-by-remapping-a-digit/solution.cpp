class Solution {
public:
    int minMaxDifference(int num) {
        string  s=  to_string(num);
        auto mi = num, ma=mi;
        int f[10]={};
        for (auto c : s) f[c-'0']++;
        for (auto c : s){
            if (c != '9' ){
                auto b=s;
                for (auto &ch : b) if (ch == c) ch = '9';
                ma = stoi(b);break;
            }

        }
        for (auto c : s){
            if (c != '0' ){
                auto b=s;
                for (auto &ch : b) if (ch == c) ch = '0';
                mi = stoi(b);break;
            }

        }
        return ma-mi;
    }
};
