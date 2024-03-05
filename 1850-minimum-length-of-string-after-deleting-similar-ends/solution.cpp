class Solution {
public:
    int minimumLength(string s) {
     int l =0, r=s.size() - 1;
     for (; l<r; ){
         if (s[l] == s[r]){
             auto c = s[l];
             while (l<=r && s[l]==c) l++;
             while (l<=r && s[r]==c) r--;
         }
         else break;
     }
     return (l<=r) ? r-l+1 : 0;
     
    }
};
