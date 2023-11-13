class Solution {
public:
    string sortVowels(string s) {
        vector<int> cnt(128);
        string v= "aeiouAEIOU";
        for (auto &c : s){
            if (v.find((c)) != string::npos)                
                cnt[c]++,c=0;;
        }
        //auto it = begin(cnt);
        int i=0;
        for (auto &c : s){
            
            if (c==0){                
                    while (cnt[i]==0 ) i++;
                c = i;cnt[i]--;
            }
        }
        return s;
    }
};