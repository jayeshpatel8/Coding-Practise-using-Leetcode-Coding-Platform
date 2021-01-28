class Solution {
public:
    int minCharacters(string a, string b) {
        int a_cnt[26]={};
        int b_cnt[26]={};
        for (auto c : a)            a_cnt[c-'a']++;
        for (auto c : b)            b_cnt[c-'a']++;
        
        int al=a.size(),bl=b.size();
        int i=0;
        int res = INT_MAX;
        
        for (i=0; i<26 ;i++){
            res = min(res, al+bl-(b_cnt[i] + a_cnt[i]));
            if (i>0) {
                a_cnt[i]+=a_cnt[i-1]; b_cnt[i]+=b_cnt[i-1];
            }
            if (i<25){
                res = min (res, (al-a_cnt[i])+b_cnt[i]);
                res = min (res, (bl-b_cnt[i])+a_cnt[i]);
            }
        }     
        
        return (res);
    }
};