class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans;
        if (k == 1){
            int smallest=1;
            for (int i=0; i<s.size(); i++){
                for (int j=0,i1=i,j1=smallest; j<s.size();j++){
                    if (s[i1] != s[j1]){
                        if (s[i1] < s[j1])
                            smallest=i;
                        break;
                    }
                    i1= (i1+1)%s.size(),j1= (j1+1)%s.size();
                }
            }
            ans = s.substr(smallest) + s.substr(0,smallest);
        }
        else{
            int freq[26]={};
            for ( auto c :s) freq[c-'a']++;
            
            for (int i =0; i< 26; i++) ans += string(freq[i],'a'+i);
        }
        return ans;
    }
};