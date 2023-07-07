class Solution {
public:
    int maxConsecutiveAnswers(string akey, int k) {
        int ans = 0,f[2]={};
        
        for (int i=0,j=0; i<akey.size(); i++){
            akey[i] = akey[i] =='T' ? 0 : 1;
            f[akey[i]]++;
            
            while (min(f[0],f[1]) > k)
                f[akey[j++]]--;
            
            ans=  max(ans, i-j+1);
        }
        return ans;
    }
};