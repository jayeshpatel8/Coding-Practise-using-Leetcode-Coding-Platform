class Solution {
public:
    int countBinarySubstrings(string s) {
     // i=0 ..j [1,0] cnt
        // j .. k [0,1]cnt
        //"00110011"
        
        int cur=1,prev=0 ,ans=0;
        
        for (int i=1; i< s.length(); i++){
            
            if (s[i-1] == s[i])
                cur++;
            else{
                 ans +=min(cur,prev);
                prev=cur; cur=1;
            }
        }
        return ans +=min(cur,prev);
    }
};