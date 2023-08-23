class Solution {
public:
    string reorganizeString(string s) {
        int f[26]={};
        for (auto c : s) f[c-'a']++;
        
        string ans;
        for (int i=0; i<s.size(); i++){
            int k=-1, c=0;
            for (int j=0; j<26; j++){
                if (ans.empty()){
                    if (f[j] > c ){
                        k=j,c=f[j];
                    }
                }
                else{
                    if (f[j] > c && ans.back() != j+'a'){
                        k=j,c=f[j];
                    }
                }
            }
            if (k==-1) return "";
            f[k]--;
            ans.push_back(k+'a');            
        }

        return ans;
    }
};