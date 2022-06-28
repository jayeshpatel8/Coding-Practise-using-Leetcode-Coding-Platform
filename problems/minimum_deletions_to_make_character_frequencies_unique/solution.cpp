class Solution {
public:
    int minDeletions(string s) {
        int f[26]={};
        for (auto c: s) f[c-'a']++;
        
        sort(begin(f),end(f));
        int ans = 0, N=s.size();
        

        for(int i=25, maxf = N; i>=0 ; i--){
            if (f[i] > maxf ){
                ans += f[i] - maxf;
                f[i] = maxf;
            }            
            maxf = max(0, f[i]-1);
            
        }
        return ans;
    }
};