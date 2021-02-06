class Solution {
public:
    int minimumLength(string s) {
        int l=0,r=s.length()-1;
        
        while (l<r){
            if (s[l]==s[r]){
                int c = s[r--];
                while(l<=r && s[l]==c)  l++;
                while(l<r && s[r]==c)  r--;
            }
            else
                break;
        }
        if (l<=r){
            return r-l+1;
        }
        return 0;
        
    }
};