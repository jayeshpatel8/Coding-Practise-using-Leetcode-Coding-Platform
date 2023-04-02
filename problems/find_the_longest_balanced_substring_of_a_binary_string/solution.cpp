class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans =0 ;
        int zeros = 0,ones=0;;
        for(int i=0; i<s.size(); i++){
            if (s[i]=='1') {ones++;
            }
            else{
                if (ones){
                    ans = max(ans, min(zeros,ones)*2);
                    zeros=ones=0;        
                }
                zeros++;
            }
        }
        return max(ans, min(zeros,ones)*2);;
    }
};