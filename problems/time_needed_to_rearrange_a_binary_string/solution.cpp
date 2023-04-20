class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        //vector<int> dp(s.size()+1);
        int prev=0;
        for (int i=0, zero =0; i<s.size(); i++){
            zero += s[i]=='0';
            if ((s[i]=='1') && zero> 0)
                prev = max(prev+1, zero);
        }
        return prev;
    }
    int secondsToRemoveOccurrences2(string s) {
        vector<int> dp(s.size());
        for (int i=1, j =0,v = 0; i<s.size(); i++){
            if (s[i]=='1'){
                while (j<i && s[j]!='0'){
                    j++;
                }
                if (s[j]=='0'){
                    dp[i] = max(v+1,i-j);
                    s[i]='0';
                    v = dp[i];
                    j++;
                }
                else v = 0;
            }
        }
        return *max_element(begin(dp),end(dp));
    }
};

/*
0101001
1010010
1100100
1101000
1110000
*/