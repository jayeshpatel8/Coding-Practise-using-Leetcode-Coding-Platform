class Solution {
public:
    string longestPalindrome(string s) {
        // abcba  abba
        // ab aca
        int n = s.size();
        int max_len=1, low,high,start=0;
        for (int i=0; i<n; i++){
            low = i-1; high=i;
            
            while (low>=0 && high <n && s[low]==s[high]){
                if (high - low + 1> max_len)
                {
                    max_len  =  high - low + 1;
                    start=low;
                }
                low--;high++;
            }
            low = i-1; high=i+1;
            while (low>=0 && high <n && s[low]==s[high]){
                if (high - low + 1> max_len)
                {
                    max_len  =  high - low + 1;
                    start=low;
                }
                low--;high++;
            }            
        }
        if (max_len<n){
            return s.substr(start,max_len);
        }
        return s;
    }
};