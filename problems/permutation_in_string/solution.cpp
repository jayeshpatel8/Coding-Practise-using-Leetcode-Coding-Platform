class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for (auto c : s1) freq[c-'a']++;
        
        for (int i = 0,N=s1.size()-1,cnt=N+1; i<s2.size(); i++){
            if (freq[s2[i]-'a']-->0)
                cnt--;
            if (i >= N){
                if (cnt==0) return true;
                if (++freq[s2[i-N]-'a'] > 0) cnt++;    
            }       
        }
        return false;
    }
};