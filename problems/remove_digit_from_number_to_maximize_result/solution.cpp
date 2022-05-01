class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans;
        for (int i=number.size()-1; i>=0; i--){
            if (number[i] == digit){
                if (ans.size()){
                    if (number[i+1] > digit)
                        ans = number.substr(0,i) + number.substr(i+1);                
                }
                else
                    ans = number.substr(0,i) + number.substr(i+1);                
                
            }
            
        }
        return ans;
    }
};