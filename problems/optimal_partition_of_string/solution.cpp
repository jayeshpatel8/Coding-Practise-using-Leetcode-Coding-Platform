class Solution {
public:
    int partitionString(string s) {
        int ans = 1, f[126]={};
        for (int i=0,j=0; i<s.size();i++ ){
            if (f[s[i]]++){
                while (j<i ) f[s[j++]]=0;
                f[s[i]]=1;
                ans++;
            }
            
        }
        return ans ;
    }
};