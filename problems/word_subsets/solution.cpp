class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int freqB[26]={};
        vector<string> ans;
        for(auto &b : B){
            int freqb[26]={};
            for (auto c : b){
                int i = c-'a';
                freqb[i]++;
                freqB[i] = max(freqB[i],freqb[i]);
            }            
        }
        for(auto &a : A){
            int freqa[26]={};
            for(auto c : a){
                freqa[c-'a']++;
            }
            int i;
            for (i=0; i<26; i++){
                if(freqa[i]<freqB[i]) break;
            }
            if (i==26) ans.push_back(a);
        }
        return ans;
    }
};