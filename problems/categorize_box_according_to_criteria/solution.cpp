class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long vol =  (long long)length * width;
        if (vol < (int)1e9) vol *= height;
        string ans="";
        if (mass >=100) ans = "Heavy";
        if (vol >= (int)1e9 || (length >= 10000 || width >= 10000 || height >= 10000 ))
            ans+= "Bulky";
        if (ans.size() > 5) return "Both";
        else if (ans.empty()) return ans = "Neither";
        return ans;
    }
};