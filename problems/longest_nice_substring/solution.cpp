class Solution {
public:
    string longestNiceSubstring(string s) {
        int l=0,st=0;
        for (int i=0; i<s.size(); i++){
            int l1=1;
            vector<int> a(26), A(26);
            for (int j = i  ,cnt=0 ;j<s.size(); j++){
                
                if (s[j] >='a' && s[j] <= 'z'){ 
                    a[s[j]-'a']=1; 
                }
                else{ 
                    A[s[j]-'A']=1; 
                }
                cnt = 1;
                for (int k=0; k<26 && cnt;k++)
                    cnt = a[k] == A[k];
                if (cnt) l1 = j-i+1;
            }
            if (l1 > l){
                l=l1, st=i;
            }
        }
        return l<2 ? "" : s.substr(st,l);
    }    
    string longestNiceSubstring2(string s) {
        int l=0,st=0;
        for (int i=0; i<s.size(); i++){
            int l1=1;
            vector<int> a(26), A(26);
            for (int j = i  ,cnt=0 ;j<s.size(); j++){
                
                if (s[j] >='a' && s[j] <= 'z'){ 
                    auto ch  = s[j]-'a'; 
                    if (a[ch] == 0){
                        a[ch]=1;
                        if (A[ch]) cnt--;
                        else
                            cnt++;
                    }
                }
                else{ 
                    auto ch  = s[j]-'A'; 
                    if (A[ch] == 0){
                        A[ch]=1;
                        if (a[ch]) cnt--;
                        else
                            cnt++;
                    }
                    
                }
                
                if (cnt==0) l1 = j-i+1;
            }
            if (l1 > l){
                l=l1, st=i;
            }
        }
        return l<2 ? "" : s.substr(st,l);
    }
};