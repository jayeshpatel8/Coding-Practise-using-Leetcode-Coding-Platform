class Solution {
public:
    string convertToTitle(int n) {
        string r;
        while (n >0){
            n -=1;
            char t = 'A' + n%26;
            n /=26;
            r = t + r;
        }
        return r;
    }
};