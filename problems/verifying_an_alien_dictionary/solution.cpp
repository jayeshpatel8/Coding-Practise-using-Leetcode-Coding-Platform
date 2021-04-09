class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
     int wt[256];
        int i=0;
        for(auto c : order) wt[c]=i++;
        
        for ( i=1; i<words.size();i++){
            int l = min(words[i-1].size(), words[i].size()),j=0;
            while(j<l){
                if (wt[words[i-1][j]] > wt[words[i][j]]) 
                    return false;
                else if (wt[words[i-1][j]] < wt[words[i][j]]) break;
                j++;
            }
            if (j==l && j<words[i-1].size()) return false;
        }
        return true;
    }
};