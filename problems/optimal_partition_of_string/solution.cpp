class Solution {
public:
    int partitionString(string s) {
        int f[128]={}, ans = 1;
        
        for (int i = 0,j=0; i<s.size(); i++){
            f[s[i]]++;        
            if (f[s[i]]<2) continue;
            while (j<i ){
                f[s[j++]]--;
            }
            ans++;
        }
        return ans;
    }
};