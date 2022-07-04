class Solution {
public:
    int maxRepOpt1(string text) {  
        int ans=0 ,N=text.size();
        vector<int> f(26),f2(26) ;
        for (int i=0;i<N; i++){
            text[i]-='a';
            f[text[i]]++;
        }
        int mask=0;
        unordered_map<int,int>M;
        for (int i=0; i<26; i++)
            M[1<<i]=i;
        for (int i=0,j=0,ch=0; i<N; i++)
        {
            char c = text[i],c2=text[j];
            if (f2[c]++==0) ch++, mask |= 1<<c;
            
            while (ch > 2 ){
                if (f2[text[j++]]-- == 1) ch--, mask ^= 1<<text[j-1];
            }
            
            c=M[mask & -mask];
            auto m2=mask & mask-1;
            c2=M[m2 & -m2];
            while(c!=c2 &&  (f2[c] > 1) && (f2[c2] > 1) ){
                if (f2[text[j++]]-- == 1) ch--, mask ^= 1<<text[j-1];
            }
            c=text[i];
            c2=text[j];

            if(f2[c]==1){
                ans= max(ans, f2[c2] + (f2[c2] < f[c2]) );    
            }
            else
                ans= max(ans, f2[c]+ (f2[c] < f[c]) );                
        }
       
        return ans;
    }
    int maxRepOpt12(string text) {  
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