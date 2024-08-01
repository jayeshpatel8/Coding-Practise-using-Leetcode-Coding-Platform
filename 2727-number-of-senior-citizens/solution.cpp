class Solution {
public:
    int countSeniors(vector<string>& details) {
        auto ans = 0;
        for (auto c : details){
            if (stoi(c.substr(11,2)) > 60) ans++;
        }
        return ans;
    }
};
