class Solution {
public:
    string sortString(string s) {
        string ans;
        int f[26]={}, cnt= 0;
        
        for (auto c: s) f[c-'a']++,cnt++;
        while (cnt> 0){
            for (int i=0; i<26 && cnt > 0 ; i++){
                if (f[i])
                    f[i]--, ans.push_back(i+'a'),cnt--;
            }
            for (int i=25; i>=0 && cnt > 0 ; i--){
                if (f[i])
                    f[i]--, ans.push_back(i+'a'),cnt--;
            }            
        }
        return ans;
    }
};