class Solution {
public:
    int countSubstrings(string s) {
        int n =  s.size();
        
        int ans = 0;
        for (int i =0 ; i<n; i++){
            
            //odd
            for (int start=i , end=i+1;  start >=0 && end <n &&  s[start] == s[end]; start--,end++ )
                ans++;
            //evn
            for (int start=i , end=i;  start >=0 && end <n &&  s[start] == s[end]; start--,end++ )
                ans++;
        }
        return ans;
    }
};
