class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (auto &s : strs){
            ans = max(ans ,  val(s));
        }
        return ans;
    }
    int val (string & s){
        int sum = 0;
        for ( auto c : s){
            if (isdigit(c)) sum=  sum*10 + c-'0';
            else return s.size();
        }
        return sum;
    }
};