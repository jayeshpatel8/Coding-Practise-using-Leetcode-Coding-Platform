class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 1, start=0,len=1;
        for(int i=0; i<s.size(); i++){
            int cnt = 1;
            for (int l=i-1,r=i+1; l>=0 && r<s.size(); l--,r++){
                if (s[l] != s[r]) break;
                cnt+=2;
            }
            if (cnt > ans)
                start = i-cnt/2,len = cnt, ans =cnt;
            
            cnt = 0;
            for (int l=i,r=i+1; l>=0 && r<s.size(); l--,r++){
                if (s[l] != s[r]) break;
                cnt+=2;
            }
            if (cnt > ans)
                start = i-(cnt/2 - 1),len = cnt, ans =cnt;
        }
        return s.substr(start,len);
    }
};