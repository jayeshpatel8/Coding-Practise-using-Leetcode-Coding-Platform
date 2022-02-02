class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int freq2[126]={};
        vector<int> ans;
        for (auto i : p) freq2[i]++;
        for (int i=0,j=0,ps = p.size()-1,c=ps+1; j<s.size(); j++){
            if (freq2[s[j]]-->=1) c--;
            if (j>=ps){
                if(c==0) ans.push_back(i);                    
                if(freq2[s[i++]]++>=0) c++;
            }
        }
        return ans;
    }
};