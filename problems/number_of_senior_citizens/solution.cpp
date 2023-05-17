class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ret = 0;
        for (auto &i : details)
        if (i[11]>='6')
            ret += (i[11]-'0' + i[12]-'0') > 6;
        return ret;
    }
};