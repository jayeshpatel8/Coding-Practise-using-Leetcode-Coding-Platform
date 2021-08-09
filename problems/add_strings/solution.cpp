class Solution {
public:
    string addStrings(string num1, string num2) {
        string  ans;
        int l1= num1.size()-1, l2=num2.size()-1, c= 0;
        while (l1>=0 || l2 >= 0){
            int sum = (l1>=0 ? num1[l1--]-'0' : 0 ) + (l2>=0 ? num2[l2--]-'0' : 0) + c;
            c = sum > 9;
            ans.push_back(sum%10 + '0');
        }
        if(c) ans.push_back(c+'0');
        reverse(begin(ans), end(ans));
        return ans;
    }
};