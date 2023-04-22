class Solution {
public:
    bool equalFrequency(string word) {
        int f[26]={};
        for (auto c : word) f[c-'a']++;

        
        
        for (int i=0; i<26; i++){
            int p=0;
            bool a=true;
            if (f[i]==0) continue;
            f[i]--;
            for (auto j : f){
                if (j){
                    if (p==0) {
                        p=j; continue;
                    }
                    else if  (p != j) {
                        a=false;
                        break;
                    }
                }
            }
            if (a) return true;
            f[i]++;
        }
        return false;      
    }
};