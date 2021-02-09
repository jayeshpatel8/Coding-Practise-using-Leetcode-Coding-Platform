class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=3,ans=0,res=0;
        int ch[256];
        ch['a']=ch['b']=ch['c']=1;
        int j=0;
        for (int i=0; i<s.size(); i++){
            if(ch[s[i]]-->0) cnt--;
            while(cnt==0){
                ans += 1;
                if(ch[s[j++]]++==0) cnt++;
            }
            res +=ans;
        }
        return res;
    }
};