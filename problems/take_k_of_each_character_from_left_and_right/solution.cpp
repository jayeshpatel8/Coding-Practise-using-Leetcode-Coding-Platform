class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k==0) return 0;
        vector<int>  cnt(3);        
        for (int i=0; i<s.size(); i++)
            cnt[s[i]-'a']++;
        
        for (int j=0; j<3; j++) if (cnt[j] <k) return -1;
        int ans= INT_MAX;
        
        for (int i =s.size(),j=i-1; i>=0; i--){
            while (j>=i && cnt[0]<k  || cnt[1]<k || cnt[2]<k) 
                cnt[s[j--]-'a']++;            
            if (cnt[0]>=k  && cnt[1]>=k && cnt[2]>=k)            
                ans= min<int>(ans,  s.size()-j+i);           
            if (i) cnt[s[i-1]-'a']--;            
        }
        
        return  ans==INT_MAX? -1 : --ans;
    }
};