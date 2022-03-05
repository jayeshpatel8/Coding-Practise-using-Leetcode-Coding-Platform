class Solution {
public:
 
    int minMovesToMakePalindrome(string s) {
        int l=0,r=s.size()-1, ans = 0;
        
        while(l <r){
            if (s[l] == s[r]) 
                l++,r--;
            else{
                int i = r-1;
                while( i > l && s[i] !=s[l]) i--;
                if (i==l) {
                    swap(s[l+1],s[l]); ans++;
                }
                else{
                    while (i<r){
                        swap(s[i],s[i+1]);
                        i++, ans++;
                    }
                    l++,r--;
                }
            }
        }
        return ans;
    }
    
};