class Solution {
public:
    bool digitCount(string num) {
        int d[11]={};
        for (auto i : num)
            d[i-'0']++;
        for (int i=0; i<num.size(); i++){
            if (num[i] - '0' != d[i]) return false;
        }
        return true;
    }
};