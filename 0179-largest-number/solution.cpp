class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (auto i : nums) s.push_back(to_string(i));
        sort(begin(s) ,end(s),[](auto &a, auto &b){ return a+b > b+a;});
        string ans;
        for (auto  i : s){
            ans +=i;
        }
        if (ans[0]=='0') return "0";
        return ans;
    }
};
