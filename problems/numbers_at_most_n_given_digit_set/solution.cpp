class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s =to_string(n);        
        int ans = 0 , s_len = s.size();
        for (int i =1; i<s_len; i++){
            ans += pow(digits.size(),i);
        }
        for ( int i=0; i<s_len; i++){
            bool same= false;
            for (auto d  : digits ){
                if (d[0] < s[i]){
                    ans += pow(digits.size(),s_len-i-1);
                }
                else if(d[0] == s[i])
                    same = true;
            }
            if (!same) return ans;
        }
        return ans+1;
    }
};