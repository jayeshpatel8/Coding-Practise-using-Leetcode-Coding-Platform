class Solution {
public:
    int maxRepOpt1(string text) {  
        int ans=0 ,N=text.size();
        vector<int> idx[26] ;
        for (int i=0;i<N; i++){
            idx[text[i]-'a'].push_back(i);
        }
        for (int c=0; c<26; c++)
        {
            int i=1,cnt1=0,cnt = 1,mx=0 ,N=idx[c].size(); 
            auto & ch = idx[c];
            for (; i<N; i++)
            {            
                if (ch[i] == ch[i-1]+1) cnt++;
                else {
                    
                    cnt1 = (ch[i] == ch[i-1]+2) ? cnt : 0;
                    cnt= 1;
                }
                mx = max(mx,cnt1+cnt);
            }            
            
            ans= max(ans, mx + (mx < N));
        }
        return ans;
    }
    int maxRepOpt1_(string text) {
  
        int ans=0;
        for (int c='a',N=text.size(); c<'=z'; c++)
        {
            int i=0,j=0,cnt = 0 ,freq=0;
            for (; i<N; i++)
            {            
                if (c != text[i]) cnt++;
                else freq++;
                if(cnt > 1){
                    cnt -= text[j++] !=c;
                }
                
            }
           // if (i==N) i--;
            ans= max(ans, min(i-j,freq));
        }
        return ans;
    }
};