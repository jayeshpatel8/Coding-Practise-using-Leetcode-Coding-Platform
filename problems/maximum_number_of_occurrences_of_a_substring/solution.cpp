class Solution {
public:
    int maxFreq(string s, int maxL, int minSize, int maxSize) {
        unordered_map<string,int>map;
        
        vector<int> ch(128,0);        
        for (int i=0 ,j = 0, uni=  0; i<s.size(); i++){
            if (++ch[s[i]] == 1) ++uni; 
            if (i-j +1 > minSize){
                if (--ch[s[j++]] == 0) --uni;                
            }
            if (i-j+1 < minSize) continue;
            if (uni <= maxL)
                map[s.substr(j,minSize)]++;       
        }
        int ans =0;
        for (auto & [k,v] : map){
            ans=   max(ans, v);            
        }

        return ans;
    }
};