class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> s;
        int n  = text.size();
        /*
        for (int i=2;i<=n; i++){
            for (int j=0; j<=n-i;j++){
                s.insert(text.substr(j,i));
            }
        }*/
        int ans=0;
        for ( int k=0; k<n; k++){
            string  j ;
            for (int i=k; i<n; i++){
                j  +=text[i] ;  
                int len=i-k+1;
                for (int q=k, p=i+1; p<n && len >0; len-- ){
                  if (text[p++]!=text[q++]) break;
                }
                if (len == 0){
                    if (s.count(j)==0){
                        ans++; s.insert(j);
                    }
                }
            }
        }
        return ans;
    }
};