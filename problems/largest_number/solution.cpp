    int comp(string a, string b){
        return (a+b > b+a);
    }
// 321 32222
class Solution {
public:
    string largestNumber(vector<int>& nums) {      

        vector<string> s;
        for (auto i : nums)
            s.push_back(to_string(i));
        
        sort(s.begin(), s.end(),comp);
        
        string res="";
        for (auto i : s)
            res +=i;
        if (res[0]=='0')return "0";
        return res;
    }
};